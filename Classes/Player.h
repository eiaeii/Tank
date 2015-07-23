#pragma once
#include "cocos2d.h"
#include "Define.h"

class Player :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Player);
	void setState(JoystickState state);

protected:
	JoystickState m_state;
};

