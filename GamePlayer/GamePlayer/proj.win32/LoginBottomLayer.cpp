#include "LoginBottomLayer.h"
#include "VisibleRect.h"
USING_NS_CC;

LoginBottomLayer::LoginBottomLayer(void)
{
}


LoginBottomLayer::~LoginBottomLayer(void)
{


}


bool LoginBottomLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCLayer::init());
		CCSprite *pBg = CCSprite::create("login/bottom.png");
		pBg->setAnchorPoint(CCPointZero);
		CC_BREAK_IF(! pBg);
		this->addChild(pBg);
		bRet = true;
	}while(0);
	return bRet;
}