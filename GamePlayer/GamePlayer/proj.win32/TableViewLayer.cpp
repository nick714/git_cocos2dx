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
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("login/login_pin.plist");
	if (!CCLayerColor::initWithColor(ccc4(0 ,38,69,255)))
	{
		return false;
	}
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCTableView *tableView = CCTableView::create(this ,CCSizeMake(800 ,376));

	tableView->setDirection(kCCScrollViewDirectionHorizontal);

	tableView->setPosition(CCPointMake(0 ,100 ));
	tableView->setDelegate(this);
	this->addChild(tableView);
	tableView->reloadData();
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

	CCString *pIndex = CCString::createWithFormat("%d", idx);
	//从队列中取出一个cell
	CCTableViewCell *cell = table->dequeueCell();
	if (!cell)
	{
		cell = new NewTableViewCell();
		cell->autorelease();
		CCSpriteFrame *pDefaultFrame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_match.png");
		CCSprite *sprite = CCSprite::create();
		CCSpriteFrame *pFrame = this->getFrameByIndex(idx);
		if (pFrame)
		{
			sprite->setDisplayFrame(pFrame);
		} 
		sprite->setAnchorPoint(CCPointZero);
        sprite->setPosition(CCPointZero);
		sprite->setTag(321);
        cell->addChild(sprite);

		CCSprite *pCaption = CCSprite::create();
		CCSpriteFrame *pCaptionFrame = this->getCaptionByIndex(idx);
		if (pCaptionFrame)
		{
			pCaption->setDisplayFrame(pCaptionFrame);
		}
		pCaption->setTag(44);
		pCaption->setAnchorPoint(CCPointZero);
		pCaption->setPosition(CCPointMake(18 ,30));
		cell->addChild(pCaption);
	} else {
		//图片
		CCSprite *sprite =  (CCSprite*)cell->getChildByTag(321);
		CCSpriteFrame *pFrame = this->getFrameByIndex(idx);
		if (pFrame)
		{
			sprite->setDisplayFrame(pFrame);
		}

		//文字
		CCSprite *pCaption =  (CCSprite*)cell->getChildByTag(44);
		CCSpriteFrame *pCaptionFrame = this->getCaptionByIndex(idx);
		if (pFrame)
		{
			pCaption->setDisplayFrame(pCaptionFrame);
		}

	}

	return cell;
}

CCSpriteFrame* TableViewLayer::getFrameByIndex(unsigned int idx)
{
	CCSpriteFrame *frame;
	if (idx == 0)
		{
			 frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_bug.png");
		}
		else if (idx == 1)
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_three.png");
		}
		else if (idx == 2)
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_four.png");
		} 
		else if (idx == 3) 
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_match.png");
		}
		else if (idx == 4)
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_private.png");
		} else {
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("item_more.png");
		}

	return frame;
}

CCSpriteFrame* TableViewLayer::getCaptionByIndex(unsigned int idx)
{
	CCSpriteFrame *frame;
	if (idx == 0)
		{
			 frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("caption_bug.png");
		}
		else if (idx == 1)
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("caption_three.png");
		}
		else if (idx == 2)
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("caption_four.png");
		} 
		else if (idx == 3) 
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("caption_match.png");
		}
		else if (idx == 4)
		{
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("caption_private.png");
		} else {
			frame =  CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("caption_more.png");
		}
	return frame;
}

unsigned int TableViewLayer::numberOfCellsInTableView(CCTableView *table)
{
    return 6;
}

