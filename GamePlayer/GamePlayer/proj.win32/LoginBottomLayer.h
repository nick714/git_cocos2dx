#pragma once
#include "cocos2d.h"

class LoginBottomLayer : public cocos2d::CCLayer
{
public:
	LoginBottomLayer(void);
	~LoginBottomLayer(void);
	virtual bool init();
	CREATE_FUNC(LoginBottomLayer);
};

