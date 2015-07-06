#include "GameScene.h"
#include "Resource.h"
#include "VisibleRect.h"
#include "Joystick.h"
#include "MapLayer.h"
USING_NS_CC;


bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B(111, 111, 111, 255)))
	{
		return false;
	}

	auto map = MapLayer::createScene();
	this->addChild(map);

	auto pJsSprite = Sprite::create("cen.png");
	auto pJsBg = Sprite::create("control_bg.png");
	auto pJoystick = Joystick::createJoystick(Vec2(VisibleRect::getVisibleRect().size.width - 100, VisibleRect::center().y), 70, pJsSprite, pJsBg, false);
	this->addChild(pJoystick);
	return true;
}

cocos2d::Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}