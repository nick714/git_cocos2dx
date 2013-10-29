#pragma once

#include "cocos2d.h"
#include "cocos-ext.h"
class NewTableViewCell : public cocos2d::extension::CCTableViewCell
{
public:
	NewTableViewCell(void);
	~NewTableViewCell(void);
	virtual void draw();
};

