#pragma once 
#include "cocos2d.h"

class GameScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void addMap();

	void addJoystick();
	CREATE_FUNC(GameScene);
};