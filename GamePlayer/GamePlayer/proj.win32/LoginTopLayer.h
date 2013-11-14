#pragma once
#include "cocos2d.h";
#include "cocos-ext.h";
class LoginTopLayer : public cocos2d::CCLayer
{
public:
	LoginTopLayer(void);
	~LoginTopLayer(void);
	virtual bool init();
	CREATE_FUNC(LoginTopLayer);
};

