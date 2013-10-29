#include "TableViewLayer.h"
#include "NewTableViewCell.h"
#include "VisibleRect.h"
#include "DDZResources.h"
USING_NS_CC;
USING_NS_CC_EXT;
TableViewLayer::TableViewLayer(void)
{
}


TableViewLayer::~TableViewLayer(void)
{
}

bool TableViewLayer::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCTableView *tableView = CCTableView::create(this ,CCSizeMake(800 ,480));

	tableView->setDirection(kCCScrollViewDirectionHorizontal);

	//tableView->setPosition(CCPointMake(20,winSize.height/2-30));
	//tableView->setPosition(VisibleRect::leftBottom());
	tableView->setDelegate(this);
	this->addChild(tableView);

	tableView->reloadData();

	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("login/login_pin.plist");

	return true;
}

void TableViewLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    CCLog("cell touched at index: %i", cell->getIdx());
}

CCSize TableViewLayer::cellSizeForTable(CCTableView *table)
{
    return CCSizeMake(220,276);
}

CCTableViewCell* TableViewLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
	CCString *string = CCString::createWithFormat("hall_number_%d.png", idx);
	//从队列中取出一个cell
	CCTableViewCell *cell = table->dequeueCell();
	if (!cell)
	{
		CCLOG("--------tableview index %d:" + idx);
		cell = new NewTableViewCell();
		cell->autorelease();
		/*CCSpriteFrame *frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_match.png");
		CCSprite *sprite = CCSprite::createWithSpriteFrame(frame);*/
		CCSprite *sprite =  CCSprite::create("login/btn_friend.png");
		/*if (idx == 0)
		{
		 sprite = CCSprite::create("login/laizi_login.png");
		}else if (idx == 1)
		{
		 sprite = CCSprite::create("login/three_login.png");
		}else if (idx == 2)
		{
		  sprite = CCSprite::create("login/four_login.png");
		} else if (idx == 3) 
		{
			sprite = CCSprite::create("login/match_login.png");
		}else if (idx == 4)
		{
			sprite = CCSprite::create("login/private_login.png");
		} else {
			sprite = CCSprite::create("login/more_login.png");
		}*/
		sprite->setAnchorPoint(CCPointZero);
        sprite->setPosition(CCPointMake(0, 0));
        cell->addChild(sprite);
	}
	return cell;
}

unsigned int TableViewLayer::numberOfCellsInTableView(CCTableView *table)
{
    return 6;
}

