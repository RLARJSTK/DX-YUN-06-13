#include "framework.h"
#include "InputManger.h"
InputManager * InputManager::_instance = nullptr;
InputManager::InputManager()
	: _curState{}
	, _oldState{}
	, _mapState{}
{
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	memcpy(_oldState, _curState, sizeof(_oldState));

	GetKeyboardState(_curState);

	for (int i = 0; i < KEYMAX; i++)
	{
		byte key = _curState[i] & 0x80;
		_curState[i] = key ? 1 : 0;

		int old = _oldState[i];
		int cur = _curState[i];

		// 전에 안눌려져있다가 지금 눌림
		if (old == 0 && cur == 1)
		{
			_mapState[i] = DOWN;
		}
		else if (old == 1 && cur == 0)
		{
			_mapState[i] = UP;
		}
		else if (old == 1 && cur == 1)
		{
			_mapState[i] = PRESS;
		}
		else
			_mapState[i] = NONE;
	}
}