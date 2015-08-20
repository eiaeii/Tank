#include "Player.h"
USING_NS_CC;

bool Player::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	
	this->initWithSpriteFrameName("player1_up_1.png");
	m_direction = stateUp;
	createAnimation();

	m_muzzle = Node::create();
	m_muzzle->setPosition(0, 10);
	this->addChild(m_muzzle);
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
		this->stopActionByTag(11);
		this->stopActionByTag(12);
		this->stopActionByTag(13);
		this->stopActionByTag(14);
		break;
	case stateUp:
	{
					m_direction = state;
					this->stopActionByTag(12);
					this->stopActionByTag(13);
					this->stopActionByTag(14);
					auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_up"));
					auto action = RepeatForever::create(animate);
					action->setTag(11);
					runAction(action);
	}
		break;
	case stateDown:
	{
					  m_direction = state;
					  this->stopActionByTag(11);
					  this->stopActionByTag(13);
					  this->stopActionByTag(14);
					  auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_down"));
					  auto action = RepeatForever::create(animate);
					  action->setTag(12);
					  runAction(action);
	}
		break;
	case stateLeft:
	{
					  m_direction = state;
					  this->stopActionByTag(11);
					  this->stopActionByTag(12);
					  this->stopActionByTag(14);
					  auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_left"));
					  auto action = RepeatForever::create(animate);
					  action->setTag(13);
					  runAction(action);
	}
		break;
	case stateRight:
	{
					   m_direction = state;
					   this->stopActionByTag(11);
					   this->stopActionByTag(12);
					   this->stopActionByTag(13);
					   auto animate = Animate::create(AnimationCache::getInstance()->getAnimation("p1_right"));
					   auto action = RepeatForever::create(animate);
					   action->setTag(14);
					   runAction(action);
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
	auto p1_fire = Animation::create();
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

	p1_up->setDelayPerUnit(0.1f);
	p1_up->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_up, "p1_up");

	p1_down->setDelayPerUnit(0.1f);
	p1_down->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_down, "p1_down");

	p1_left->setDelayPerUnit(0.1f);
	p1_left->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_left, "p1_left");

	p1_right->setDelayPerUnit(0.1f);
	p1_right->setRestoreOriginalFrame(true);
	AnimationCache::getInstance()->addAnimation(p1_right, "p1_right");
}
