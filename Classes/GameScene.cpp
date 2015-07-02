#include "GameScene.h"
#include "Resource.h"
#include "VisibleRect.h"
#include "Joystick.h"
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

	auto pJsSprite = Sprite::create("cen.png");
	auto pJsBg = Sprite::create("control_bg.png");
	auto pJoystick = Joystick::createJoystick(Vec2(100, 250), 70, pJsSprite, pJsBg, false);

	this->addChild(pJoystick);
	return true;
}