#include "TitleScene.h"
#include "Resource.h"
#include "VisibleRect.h"
#include "GameScene.h"

USING_NS_CC;

Scene* Title::createScene()
{
	auto scene = Scene::create();
	auto layer = Title::create();
	scene->addChild(layer);
	return scene;
}


bool Title::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto city = Sprite::create(Img_BattleCity);
	city->setPosition(VisibleRect::center());
	this->addChild(city);

	//开始按钮
	auto lableStart = Label::createWithTTF("Start Game", Font_Button, 30);
	//lableStart->enableShadow(Color4B(0, 255, 255, 100), Size(5, 10));
	//lableStart->enableGlow(Color4B(0, 0, 255, 255));
	auto itemStart = MenuItemLabel::create(lableStart, CC_CALLBACK_1(Title::menuStartGameCallback, this));
	auto menuStart = Menu::create(itemStart, nullptr);
	menuStart->setPosition(VisibleRect::center().x, VisibleRect::center().y - 100);
	this->addChild(menuStart);

	//结束按钮
	auto lableClose = Label::createWithTTF("Exit", Font_Button, 30);
	auto itemClose = MenuItemLabel::create(lableClose, CC_CALLBACK_1(Title::menuCloseCallback, this));
	auto menuClose = Menu::create(itemClose, nullptr);
	menuClose->setPosition(VisibleRect::center().x, VisibleRect::center().y - 150);
	menuClose->alignItemsHorizontallyWithPadding(0);
	this->addChild(menuClose);

	return true;
}

void Title::menuStartGameCallback(cocos2d::Ref* pSender)
{
	auto scene = GameScene::createScene();
	Director::getInstance()->replaceScene(scene);
}

void Title::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}