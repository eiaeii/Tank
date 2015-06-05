#include "TitleScene.h"
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

	return true;
}