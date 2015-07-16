#pragma once
#include "cocos2d.h"

class Player;

class MapLayer :
	public cocos2d::LayerColor
{
public:
	virtual bool init();
	CREATE_FUNC(MapLayer);
	static cocos2d::Scene* createScene();

protected:
	cocos2d::TMXObjectGroup* m_pObjectsGroup;
	Player* m_pPlayer;
	float m_fScale;
};

