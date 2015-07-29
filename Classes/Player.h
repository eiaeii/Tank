#pragma once
#include "cocos2d.h"
#include "Define.h"

class Player :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Player);
	void setAction(JoystickState state);

protected:
	JoystickState m_state;

protected:

	void createAnimation();
};

