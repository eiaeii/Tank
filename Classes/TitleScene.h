#pragma once
#include "cocos2d.h"

class Title : public cocos2d::Layer
{
public:

	static cocos2d::Scene* createScene();

	virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);
	void menuCloseCallback(cocos2d::Ref* pSender);
	void preloadResources();

	CREATE_FUNC(Title);
};

