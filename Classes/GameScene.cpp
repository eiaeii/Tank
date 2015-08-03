#include "GameScene.h"
#include "Resource.h"
#include "VisibleRect.h"
#include "Joystick.h"
#include "MapLayer.h"
#include "SimpleAudioEngine.h"
#include "Resource.h"
#include "Player.h"
#include "Define.h"
USING_NS_CC;

bool GameScene::init()
{
	if (!LayerColor::initWithColor(Color4B(111, 111, 111, 255)))
	{
		return false;
	}
	addMap();
	addJoystick();
	addButton();
	this->setTag(GameScene_Tag);
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(Music_Bg1);
	return true;
}

cocos2d::Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

void GameScene::addMap()
{
	auto map = MapLayer::createScene();
	this->addChild(map);
}

void GameScene::addJoystick()
{
	auto pJsSprite = Sprite::createWithSpriteFrameName("cen.png");
	auto pJsBg = Sprite::createWithSpriteFrameName("control_bg.png");
	auto pJoystick = Joystick::createJoystick(Vec2(100, VisibleRect::center().y), 70, pJsSprite, pJsBg, false);
	this->addChild(pJoystick);
}

void GameScene::addButton()
{
	auto fireItem = MenuItemSprite::create(
		Sprite::createWithSpriteFrameName("fire_button_default.png"),
		Sprite::createWithSpriteFrameName("fire_button_press.png"),
		CC_CALLBACK_0(GameScene::fire, this));

	fireItem->setPosition(Vec2(VisibleRect::getVisibleRect().size.width - 100, VisibleRect::center().y));
	auto menu = Menu::create(fireItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
}

void GameScene::fire()
{
	auto player = static_cast<Player*>(getChildByTag(Player1_Tag));
	player->fire();
}