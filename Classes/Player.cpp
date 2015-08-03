#include "Player.h"
USING_NS_CC;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	this->setTag(Player1_Tag);
	this->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("player1_up_1.png"));
	m_direction = stateUp;
	createAnimation();

	return true;
}


void Player::setMoveState(JoystickState state)
{
	if (m_state == state)
	{
		return;
	}

	switch (state)
	{
	case stateNothing:
		this->stopAllActions();
		break;
	case stateUp:
	{
					m_direction = state;
					this->stopAllActions();
					auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_up"));
					runAction(RepeatForever::create(animate));
	}
		break;
	case stateDown:
	{
					  m_direction = state;
					  this->stopAllActions();
					  auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_down"));
					  runAction(RepeatForever::create(animate));
	}
		break;
	case stateLeft:
	{
					  m_direction = state;
					  this->stopAllActions();
					  auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_left"));
					  runAction(RepeatForever::create(animate));
	}
		break;
	case stateRight:
	{
					   m_direction = state;
					   this->stopAllActions();
					   auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_right"));
					   runAction(RepeatForever::create(animate));
	}
		break;
	default:
		break;
	}
	
	m_state = state;
}


void Player::createAnimation()
{
	auto p1_up = Animation::create();
	auto p1_down = Animation::create();
	auto p1_left = Animation::create();
	auto p1_right = Animation::create();
	char szName[100] = { 0 };

	for (int i = 1; i < 5; i++)
	{
		sprintf(szName, "player1_up_%d.png", i);
		p1_up->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(szName));

		sprintf(szName, "player1_down_%d.png", i);
		p1_down->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(szName));

		sprintf(szName, "player1_left_%d.png", i);
		p1_left->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(szName));

		sprintf(szName, "player1_right_%d.png", i);
		p1_right->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(szName));
	}

	p1_up->setDelayPerUnit(0.4f / 4.0f);
	p1_up->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_up, "p1_up");

	p1_down->setDelayPerUnit(0.4f / 4.0f);
	p1_down->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_down, "p1_down");

	p1_left->setDelayPerUnit(0.4f / 4.0f);
	p1_left->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_left, "p1_left");

	p1_right->setDelayPerUnit(0.4f / 4.0f);
	p1_right->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_right, "p1_right");
}

void Player::fire()
{
	
}