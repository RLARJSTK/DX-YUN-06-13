#include "framework.h"
#include "Timer.h"
Timer* Timer::_instance = nullptr;
Timer::Timer()
{
	// 1�ʵ��� CPU�� �������� ��ȯ�ϴ� �Լ�
	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);
	// ���� ������
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

	// 1/�ʴ� ������
	_timeScale = 1.0f / (double)_periodFrequency;
}

Timer::~Timer()
{
}

void Timer::Update()
{
	// (���ݱ��� ������ Ƚ�� - ó���� ������ Ƚ��) * (1 / �ʴ�������) => RunTime
	// (���ݱ��� ����Ƚ Ƚ�� - �� ������Ʈ�� ��ġ�� ���� ������ Ƚ��) * (1 / �ʴ�������) => DELTA Time
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

	// �� ������Ʈ�� ��ġ�� ���� ������ Ƚ��
	_lastTime = _curTime;

	_frameCount++;
	_oneSecCount += _timeTickElased;
	_runTime += _timeTickElased;

	// 1�ʸ��� �����ؾߵǴ� ����
	if (_oneSecCount >= 1.0)
	{
		_oneSecCount = 0;
		_frameCount = 0;

		_frameRate = _frameCount;
	}
}