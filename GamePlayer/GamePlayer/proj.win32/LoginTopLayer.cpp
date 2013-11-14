#include "LoginTopLayer.h"
#include "VisibleRect.h"
USING_NS_CC;
USING_NS_CC_EXT;
LoginTopLayer::LoginTopLayer(void)
{
}


LoginTopLayer::~LoginTopLayer(void)
{
}


bool LoginTopLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());

		//背景
		CCSprite *pBg = CCSprite::create("login/top.png");
		pBg->setAnchorPoint(CCPointZero);
		CC_BREAK_IF(! pBg);
		this->addChild(pBg);

		//博雅斗地主 标题
		CCSprite *pTitle = CCSprite::create("login/top_tittle.png");
		CC_BREAK_IF(! pTitle);
		pTitle->setPositionX(410);
		pTitle->setPositionY(40);
		this->addChild(pTitle);

		//每日必做
		//CCString title = CCString::create("标题");
		CCLabelTTF *titleButton = CCLabelTTF::create("----", "Marker Felt", 32);
		CCScale9Sprite *pBackground = CCScale9Sprite::create("login/btn_day.png");
		pBackground->setContentSize(CCSizeMake(56 ,48));
		CCControlButton *button = CCControlButton::create(pBackground );
		CC_BREAK_IF(! button);
		button->setPosition(100 ,10);
		//pBackground->set
		this->addChild(button);


		bRet = true;
	}while(0);
	return bRet;
}