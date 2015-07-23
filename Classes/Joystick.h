#pragma once
#include "cocos2d.h"
#include "Define.h"


class Joystick :
	public cocos2d::Layer
{
public:
	virtual bool	 init();
	CREATE_FUNC(Joystick);

	//初始化：oPos是摇杆中心，fRadius是摇杆半径，pJsSprite是摇杆控制点，pJsBg是摇杆背景，bFollowRole是否跟随用户点击
	static Joystick* createJoystick(cocos2d::Vec2 oPos, float fRadius, cocos2d::Sprite* pJsSprite, cocos2d::Sprite* pJsBg, bool bFollowRole);

	//启动摇杆
	void active();

	//关闭摇杆
	void inActive();
	static JoystickState getJoystickState();
	
private:
	Joystick* initJoystick(cocos2d::Vec2 oPos, float fRadius, cocos2d::Sprite* pJsSprite, cocos2d::Sprite* pJsBg, bool bFollowRole);
	cocos2d::Point getDirection();
	float getVelocity();
	bool TouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void TouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void TouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
	void addEventTouch();
	void  update(float delta);

	//计算摇杆方向
	JoystickState calculateRetation();
private:

	cocos2d::Point m_oCenterPoint;//摇杆中心  
	cocos2d::Point m_oCurrentPoint;//摇杆当前位置  

	bool m_bActive;//是否激活摇杆
	bool m_bFollowRole;//是否跟随用户点击

	float m_fRadius;//摇杆半径

	cocos2d::Sprite *m_pJsSprite;
	cocos2d::Sprite *m_pJsBg;

	//摇杆方向
	static JoystickState m_jsState;

};
