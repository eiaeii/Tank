#pragma once
#include "cocos2d.h"
#include "Define.h"


class Joystick :
	public cocos2d::Layer
{
public:
	virtual bool	 init();
	CREATE_FUNC(Joystick);

	//��ʼ����oPos��ҡ�����ģ�fRadius��ҡ�˰뾶��pJsSprite��ҡ�˿��Ƶ㣬pJsBg��ҡ�˱�����bFollowRole�Ƿ�����û����
	static Joystick* createJoystick(cocos2d::Vec2 oPos, float fRadius, cocos2d::Sprite* pJsSprite, cocos2d::Sprite* pJsBg, bool bFollowRole);

	//����ҡ��
	void active();

	//�ر�ҡ��
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

	//����ҡ�˷���
	JoystickState calculateRetation();
private:

	cocos2d::Point m_oCenterPoint;//ҡ������  
	cocos2d::Point m_oCurrentPoint;//ҡ�˵�ǰλ��  

	bool m_bActive;//�Ƿ񼤻�ҡ��
	bool m_bFollowRole;//�Ƿ�����û����

	float m_fRadius;//ҡ�˰뾶

	cocos2d::Sprite *m_pJsSprite;
	cocos2d::Sprite *m_pJsBg;

	//ҡ�˷���
	static JoystickState m_jsState;

};
