#pragma once
#include "ScrollViewLayer.h"

class CCBReader;
//尼玛，需要加载ccbi文件，这个demo先不做了
class ScrollViewLayerLoader : public cocos2d::extension::CCLayerLoader
{
public:
        CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ScrollViewLayerLoader, loader);
protected:
        CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(ScrollViewLayer);
};

