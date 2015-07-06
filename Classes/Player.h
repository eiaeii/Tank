#pragma once
#include "cocos2d.h"

typedef enum
{
	pUp = 1,
	pDown,
	pLeft,
	pRight,
	pFire,
	pStay,
	pPause,
}PlayerAction;

class Player :
	public cocos2d::Sprite
{
public:
	virtual bool init();
	CREATE_FUNC(Player);
};

