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
	if (!CCLayerColor::initWithColor(ccc4(0 ,38,69,255)))
	{
		return false;
	}
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCTableView *tableView = CCTableView::create(this ,CCSizeMake(800 ,376));

	tableView->setDirection(kCCScrollViewDirectionHorizontal);

	//tableView->setPosition(CCPointMake(20,winSize.height/2-30));
	tableView->setPosition(CCPointMake(0 ,100 ));
	//tableView->setVerticalFillOrder(kCCTableViewFillTopDown);
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
    return CCSizeMake(220,376);
}

CCTableViewCell* TableViewLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
	CCString *string = CCString::createWithFormat("hall_number_%d.png", idx);
	//从队列中取出一个cell
	CCTableViewCell *cell = table->dequeueCell();
	if (!cell)
	{
		cell = new NewTableViewCell();
		cell->autorelease();
		/*CCSpriteFrame *frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_match.png");
		CCSprite *sprite = CCSprite::createWithSpriteFrame(frame);*/
		CCSprite *sprite =  CCSprite::create("login/laizi_login.png");
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
		//sprite->setContentSize(CCSizeMake(100 ,180));
		sprite->setAnchorPoint(CCPointZero);
        sprite->setPosition(CCPointZero);
        cell->addChild(sprite);
	}
	return cell;
}

unsigned int TableViewLayer::numberOfCellsInTableView(CCTableView *table)
{
    return 20;
}

