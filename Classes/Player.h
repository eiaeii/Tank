#pragma once
#include "cocos2d.h"
#include "Define.h"

class Player :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Player);
	void setMoveState(JoystickState state);
	void fire(); //开炮
protected:
	JoystickState m_state; //虚拟摇杆动作
	JoystickState m_direction; //角色方向
	cocos2d::Sprite* m_muzzle; //炮口
protected:

	void createAnimation();
};

