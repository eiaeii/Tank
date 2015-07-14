#pragma once
#include "cocos2d.h"
class MapLayer :
	public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);
	static cocos2d::Scene* createScene();

protected:
	cocos2d::TMXObjectGroup* m_pObjectsGroup;
	
};

