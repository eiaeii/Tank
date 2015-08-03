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
	void fire(); //����
protected:
	JoystickState m_state; //����ҡ�˶���
	JoystickState m_direction; //��ɫ����
	cocos2d::Sprite* m_muzzle; //�ڿ�
protected:

	void createAnimation();
};

