#include "MapLayer.h"
#include "Resource.h"
#include "VisibleRect.h"
USING_NS_CC;

bool MapLayer::init()
{
	if (!LayerColor::initWithColor(Color4B(0, 0, 0, 255), VisibleRect::getVisibleRect().size.height, VisibleRect::getVisibleRect().size.width))
	{
		return false;
	}

	auto level = TMXTiledMap::create(Map_Level1);
	auto scale = VisibleRect::getVisibleRect().size.height / level->getContentSize().height;
	level->setScale(scale);
	this->addChild(level);
	this->setPosition((VisibleRect::getVisibleRect().size.width - this->getContentSize().width) / 2, 0);
	m_pObjectsGroup = level->objectGroupNamed("objects");
	
	return true;
}


Scene* MapLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = MapLayer::create();
	scene->addChild(layer);
	return scene;
}
