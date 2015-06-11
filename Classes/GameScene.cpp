#include "GameScene.h"
#include "Resource.h"
#include "VisibleRect.h"
USING_NS_CC;

cocos2d::Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto level = TMXTiledMap::create(Map_Level1);
	auto scale = VisibleRect::getVisibleRect().size.height / level->getContentSize().height;
	level->setScale(scale);
	auto mapSize = level->getContentSize();
	level->setPosition((VisibleRect::getVisibleRect().size.width - mapSize.width) / 2, 0);
	this->addChild(level);
	return true;
}