#pragma once
#include "ScrollViewLayer.h"

class CCBReader;
//���꣬��Ҫ����ccbi�ļ������demo�Ȳ�����
class ScrollViewLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ScrollViewLayerLoader, loader);
protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ScrollViewLayer);
};

