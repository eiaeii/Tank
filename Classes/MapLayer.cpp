#include "MapLayer.h"
#include "Resource.h"
#include "VisibleRect.h"
#include "Player.h"

USING_NS_CC;

bool MapLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 255), VisibleRect::getVisibleRect().size.height, VisibleRect::getVisibleRect().size.width))
	{
		return false;
	}

	auto level = TMXTiledMap::create(Map_Level1);
	m_fScale = VisibleRect::getVisibleRect().size.height / level->getContentSize().height;
	level->setScale(m_fScale);
	this->addChild(level);
	this->setPosition((VisibleRect::getVisibleRect().size.width - this->getContentSize().width) / 2, 0);
	m_pObjectsGroup = level->getObjectGroup("objects");
	auto playerPoint = m_pObjectsGroup->getObject("player1");
	m_pPlayer = Player::create();
	float playerX = playerPoint.at("x").asFloat();
	float playerY = playerPoint.at("y").asFloat();
	m_pPlayer->setScale(m_fScale);
	m_pPlayer->setPosition(playerX * m_fScale, playerY * m_fScale);
	this->addChild(m_pPlayer);
	return true;
}


Scene* MapLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = MapLayer::create();
	scene->addChild(layer);
	return scene;
}
