#include "Player.h"
USING_NS_CC;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	this->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("p1tankU.PNG"));

	return true;
}


void Player::setState(JoystickState state)
{
	if (m_state == state)
	{
		return;
	}

	switch (state)
	{
	case stateNothing:
		break;
	case stateUp:
		this->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("p1tankU.PNG"));
		break;
	case stateDown:
		this->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("p1tankD.PNG"));
		break;
	case stateLeft:
		this->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("p1tankL.PNG"));
		break;
	case stateRight:
		this->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("p1tankR.PNG"));
		break;
	default:
		break;
	}

	m_state = state;
}