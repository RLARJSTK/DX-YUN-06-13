#include "framework.h"
#include "Timer.h"
Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	// 1초동안 CPU의 진동수를 반환하는 함수
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);
	// 현재 진동수
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

	// 1/초당 진동수
	_timeScale = 1.0f / (double)_periodFrequency;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	// (지금까지 진동한 횟수 - 처음에 진동한 횟수) * (1 / 초당진동수) => RunTime
	// (지금까지 진동횟 횟수 - 이 업데이트를 거치기 전의 진동한 횟수) * (1 / 초당진동수) => DELTA Time
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	_timeTickElased = (double)(_curTime - _lastTime) * _timeScale;
	if (_lockFPS != 0)
	{
		while (_timeTickElased < (1.0 / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_timeTickElased = (double)(_curTime - _lastTime) * _timeScale;
		}
	}

	// 이 업데이트를 거치기 전의 진동한 횟수
	_lastTime = _curTime;

	_frameCount++;
	_oneSecCount += _timeTickElased;
	_runTime += _timeTickElased;

	// 1초마다 갱신해야되는 정보
	if (_oneSecCount >= 1.0)
	{
		_oneSecCount = 0;
		_frameCount = 0;

		_frameRate = _frameCount;
	}
}