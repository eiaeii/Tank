#include "Joystick.h"
USING_NS_CC;

JoystickState Joystick::m_jsState = stateNothing;

bool Joystick::init()
{
	if (!Layer::init())
	{
		return false;
	}
	addEventTouch();
	return true;
}

void Joystick::active()
{
	if (!m_bActive)
	{
		m_bActive = true;
	}
	this->scheduleUpdate();
}

void Joystick::inActive()
{
	if (m_bActive)
	{
		m_bActive = false;
	}
	this->unscheduleUpdate();
}

Point Joystick::getDirection()
{
	return (m_oCenterPoint - m_oCurrentPoint).getNormalized();
}

Joystick* Joystick::initJoystick(cocos2d::Vec2 oPos, float fRadius, cocos2d::Sprite* pJsSprite, cocos2d::Sprite* pJsBg, bool bFollowRole)
{
	m_bFollowRole = bFollowRole;
	m_bActive = false;
	m_fRadius = fRadius;
	if (!m_bFollowRole)
	{
		m_oCenterPoint = oPos;
	}
	else
	{
		m_oCenterPoint = Point::ZERO;
	}
	m_oCurrentPoint = m_oCenterPoint;
	m_pJsSprite = pJsSprite;
	m_pJsSprite->setPosition(m_oCenterPoint);
	m_pJsBg = pJsBg;
	m_pJsBg->setPosition(m_oCenterPoint);
	this->addChild(pJsBg);
	this->addChild(m_pJsSprite);
	if (m_bFollowRole)
	{
		this->setVisible(true);
	}
	this->active();
	return this;
}

Joystick* Joystick::createJoystick(cocos2d::Vec2 oPos, float fRadius, cocos2d::Sprite* pJsSprite, cocos2d::Sprite* pJsBg, bool bFollowRole)
{
	auto joy = Joystick::create();
	joy->initJoystick(oPos, fRadius, pJsSprite, pJsBg, bFollowRole);
	return joy;
}

float Joystick::getVelocity()
{
	return m_oCenterPoint.getDistance(m_oCurrentPoint);
}

bool Joystick::TouchBegan(Touch *pTouch, Event *pEvent)
{
	if (!m_bActive)
	{
		return false;
	}
	this->setVisible(true);
	Vec2 touchpoint = pTouch->getLocationInView();
	touchpoint = Director::getInstance()->convertToGL(touchpoint);
	if (!m_bFollowRole)
	{
		if (touchpoint.getDistance(m_oCenterPoint)>m_fRadius)
		{
			return false;
		}
	}
	m_oCurrentPoint = touchpoint;
	if (m_bFollowRole)
	{
		m_oCenterPoint = m_oCurrentPoint;
		m_pJsSprite->setPosition(m_oCurrentPoint);
		m_pJsBg->setPosition(m_oCurrentPoint);
	}
	return true;
}

void Joystick::TouchMoved(Touch *pTouch, Event *pEvent)
{
	Vec2 touchpoint = pTouch->getLocationInView();
	touchpoint = Director::getInstance()->convertToGL(touchpoint);
	if (touchpoint.getDistance(m_oCenterPoint) > m_fRadius)
	{
		m_oCurrentPoint = (touchpoint - m_oCenterPoint).getNormalized() * m_fRadius + m_oCenterPoint;
	}
	else
	{
		m_oCurrentPoint = touchpoint;
	}
}

void Joystick::TouchEnded(Touch *pTouch, Event *pEvent)
{
	m_oCurrentPoint = m_oCenterPoint;
	if (m_bFollowRole)
	{
		this->setVisible(true);
	}
}

void Joystick::addEventTouch()
{

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(Joystick::TouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(Joystick::TouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(Joystick::TouchEnded, this);
	listener->setSwallowTouches(true);//是否向下传递
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void Joystick::update(float delta)
{
	m_pJsSprite->setPosition(m_pJsSprite->getPosition() + ((m_oCurrentPoint - m_pJsSprite->getPosition())*0.5));
	static float deltaTimes = 0.0f;
	deltaTimes += delta;
	if (deltaTimes >= 0.2f)
	{
		deltaTimes = 0;
		m_jsState = calculateRetation();
	}
}

JoystickState Joystick::calculateRetation()
{
	auto direction = getDirection();
	auto velocity = getVelocity();

	auto angle = atan2(direction.x, direction.y) * 180 / 3.14;
	if (angle == 0)
	{
		return stateNothing;
	}
	if (angle < -45 && angle >-135) return stateRight;
	if (angle > 45 && angle <135) return stateLeft;
	if (angle < 45 && angle > -45) return stateDown;
	if (angle >135 || angle < -135) return stateUp;

	return stateNothing;
}

JoystickState Joystick::getJoystickState()
{
	return m_jsState;
}