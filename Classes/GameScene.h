#pragma once 
#include "cocos2d.h"

class GameScene : public cocos2d::LayerColor
{
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(GameScene);

	virtual bool init();

	void addMap();

	void addJoystick();

	void addButton();

	void fire(); //©╙ез
};