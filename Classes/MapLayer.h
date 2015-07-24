#pragma once
#include "cocos2d.h"
#include "Define.h"

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
	float m_playerSpeed;
	cocos2d::Size m_mapSize;
	cocos2d::TMXTiledMap* m_pMap;
	cocos2d::TMXLayer* m_pBackground;
	cocos2d::ValueMap m_valueMap;
protected:
	void  update(float delta);
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	//×ª»»³ÉTiledMap×ø±ê
	cocos2d::Vec2 positionToTiledPoint(cocos2d::Vec2 pos);
};

