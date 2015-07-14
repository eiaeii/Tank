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


void Player::setAction(PlayerAction objAction)
{
	switch (objAction)
	{
	case pUp:
		break;
	default:
		break;
	}
}