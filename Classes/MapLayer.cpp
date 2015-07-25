#include "MapLayer.h"
#include "Resource.h"
#include "VisibleRect.h"
#include "Player.h"
#include "Joystick.h"


USING_NS_CC;

bool MapLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 255), VisibleRect::getVisibleRect().size.height, VisibleRect::getVisibleRect().size.width))
	{
		return false;
	}

	m_pMap = TMXTiledMap::create(Map_Level1);
	m_pBackground = m_pMap->getLayer("background");
	m_fScale = VisibleRect::getVisibleRect().size.height / m_pMap->getContentSize().height;
	m_pMap->setScale(m_fScale);
	m_mapSize = m_pMap->getContentSize() * m_fScale;
	this->addChild(m_pMap);
	this->setPosition((VisibleRect::getVisibleRect().size.width - this->getContentSize().width) / 2, 0);
	m_pObjectsGroup = m_pMap->getObjectGroup("objects");
	auto playerPoint = m_pObjectsGroup->getObject("player1");
	m_pPlayer = Player::create();
	float playerX = playerPoint.at("x").asFloat();
	float playerY = playerPoint.at("y").asFloat();
	m_pPlayer->setScale(m_fScale);
	m_pPlayer->setPosition(playerX * m_fScale, playerY * m_fScale);
	this->addChild(m_pPlayer);
	m_playerSpeed = 2.0f;
	this->scheduleUpdate();
	return true;
}


Scene* MapLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = MapLayer::create();
	scene->addChild(layer);
	return scene;
}

void  MapLayer::update(float delta)
{
	auto state = Joystick::getJoystickState();
	m_pPlayer->setState(state);
	switch (state)
	{
	case stateNothing:
		break;
	case stateUp:
		MoveUp();
		break;
	case stateDown:
		MoveDown();
		break;
	case stateLeft:
		MoveLeft();
		break;
	case stateRight:
		MoveRight();
		break;
	default:
		break;
	}
}

void MapLayer::MoveUp()
{
	auto pos1 = m_pPlayer->getPosition();
	auto delta = Vec2(0, m_playerSpeed);
	auto pos2 =pos1 + delta;
	auto checkPoint = Vec2(pos2.x, pos2.y + m_pPlayer->getContentSize().height / 2);
	if (checkPoint.y > m_mapSize.height)
	{
		return;
	}

	if (canMove(checkPoint))
	{
		m_pPlayer->setPosition(pos2);
	}
}

void MapLayer::MoveDown()
{
	auto pos1 = m_pPlayer->getPosition();
	auto delta = Vec2(0, -m_playerSpeed);
	auto pos2 = pos1 + delta;
	auto checkPoint = Vec2(pos2.x, pos2.y - m_pPlayer->getContentSize().height / 2);
	if (checkPoint.y < 0)
	{
		return;
	}

	if (canMove(checkPoint))
	{
		m_pPlayer->setPosition(pos2);
	}
}

void MapLayer::MoveLeft()
{
	auto pos1 = m_pPlayer->getPosition();
	auto delta = Vec2(-m_playerSpeed, 0);
	auto pos2 = pos1 + delta;
	auto checkPoint = Vec2(pos2.x - m_pPlayer->getContentSize().width / 2, pos2.y);
	if (checkPoint.x < 0)
	{
		return;
	}
	
	if (canMove(checkPoint))
	{
		m_pPlayer->setPosition(pos2);
	}
}

void MapLayer::MoveRight()
{
	auto pos1 = m_pPlayer->getPosition();
	auto delta = Vec2(m_playerSpeed, 0);
	auto pos2 = pos1 + delta;
	auto checkPoint = Vec2(pos2.x + m_pPlayer->getContentSize().width / 2, pos2.y);
	if (checkPoint.x > m_mapSize.width)
	{
		return;
	}
	
	if (canMove(checkPoint))
	{
		m_pPlayer->setPosition(pos2);
	}
}

Vec2 MapLayer::positionToTiledPoint(Vec2 pos)
{
	auto temp = pos / m_fScale;
	return  Vec2((int)(temp.x / m_pMap->getTileSize().width), m_pMap->getMapSize().height - 1 - (int)(temp.y / m_pMap->getTileSize().height));
}

bool MapLayer::canMove(cocos2d::Vec2 pos)
{
	auto tiledPoint = positionToTiledPoint(pos);
	tiledPoint.x = tiledPoint.x < 0 ? 0 : tiledPoint.x;
	tiledPoint.x = tiledPoint.x >= m_pMap->getMapSize().width ? m_pMap->getMapSize().width - 1 : tiledPoint.x;
	tiledPoint.y = tiledPoint.y < 0 ? 0 : tiledPoint.y;
	tiledPoint.y = tiledPoint.y >= m_pMap->getMapSize().height ? m_pMap->getMapSize().height -1 : tiledPoint.y;
	auto tiledID = m_pBackground->getTileGIDAt(tiledPoint);
	auto rem = tiledID % 28;
	if (rem > 0 && rem < 8)
	{
		return false;
	}
	return true;
}