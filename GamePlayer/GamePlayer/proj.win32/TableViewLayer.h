#pragma once
#include "cocos2d.h"
#include "cocos-ext.h"
class TableViewLayer : public cocos2d::CCLayer ,public cocos2d::extension::CCTableViewDataSource ,public cocos2d::extension::CCTableViewDelegate
{
public:
	TableViewLayer(void);
	~TableViewLayer(void);
	virtual bool init();



	CREATE_FUNC(TableViewLayer);

	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView *view) {};
	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView *view){};
	virtual void tableCellTouched(cocos2d::extension::CCTableView *table ,cocos2d::extension::CCTableViewCell *cell);
	virtual cocos2d::CCSize cellSizeForTable(cocos2d::extension::CCTableView *table);
	virtual cocos2d::extension::CCTableViewCell *tableCellAtIndex(cocos2d::extension::CCTableView *table ,unsigned int index);
	virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table);


};
