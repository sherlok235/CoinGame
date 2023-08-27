#include "coinitem.h"

namespace CoinSpace {


Coin_0::Coin_0():CoinItem(0)
{
    mType = 0;
    setFrameRect(cocos2d::Size(65,65));
}

Coin_0::Coin_0(int type):CoinItem(type)
{
    if(coin_4_IsCreated && coin_7_IsCreated)
        exit(0);
    mType = type;
}

int Coin_0::getType() const
{
    return mType;
}

void Coin_0::setType(short type)
{
    mType = type;

}

Coin_0::~Coin_0()
{

}

CoinItem::CoinItem()
{
    temp = true;
}

CoinItem::CoinItem(int type)
{
    setDefaultImage(type);
    temp = true;
}

bool CoinItem::onTouchBegan(Touch *touch, Event *event)
{
    initialpos = touch->getLocation();
     return true;
}

void CoinItem::onTouchEnded(Touch *touch, Event *event)
{
   initialpos = touch->getLocation();

}

void CoinItem::onTouchMoved(Touch *touch, Event *event)
{
    targetPosition = touch->getLocation();
//    moveToTarget();
    auto currentPos = initialpos;

    auto direction = targetPosition - currentPos;

    // Don't normalize as we want to move exactly to target

    auto newPos = currentPos + direction;

    // Clamp new position to visible bounds
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    newPos.x = std::min(visibleSize.width-100, std::max(0.f, newPos.x));
    newPos.y = std::min(visibleSize.height-100, std::max(0.f, newPos.y));

    // Update position, clamped to bounds
    this->setPosition(newPos);
}
// you should to delete it
void CoinItem::moveToTarget() {

    auto currentPos = initialpos;

    auto direction = targetPosition - currentPos;

    // Don't normalize as we want to move exactly to target

    auto newPos = currentPos + direction;

    // Clamp new position to visible bounds
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    newPos.x = std::min(visibleSize.width, std::max(0.f, newPos.x));
    newPos.y = std::min(visibleSize.height, std::max(0.f, newPos.y));

    // Update position, clamped to bounds
    this->setPosition(newPos);

}
CoinItem::~CoinItem()
{

}

void CoinItem::setDefaultImage( int type)
{
    this->setTexture(("coins_" + std::to_string(type) + ".png"));
    //    this->autorelease();
}

void CoinItem::setHeightRect(float newHeightRect)
{
    heightRect = newHeightRect;
}

void CoinItem::setFrameRect(cocos2d::Size size)
{
    auto frame = new cocos2d::SpriteFrame();
    frame->setRect(cocos2d::Rect(this->getPosition(),cocos2d::Size(size.width,size.height)));
    this->createWithSpriteFrame(frame);
}

void CoinItem::setWidthRect(float newWidthRect)
{
    widthRect = newWidthRect;
}

Coin_1::Coin_1():Coin_0(1)
{
    Coin_0::mType = 1;
    setFrameRect(cocos2d::Size(86,92));
    //    setDefaultImage(mType);
}

Coin_1::~Coin_1()
{

}

Coin_2::Coin_2():Coin_0(2)
{
    Coin_0::mType = 2;
    setFrameRect(cocos2d::Size(92,100));
}

Coin_2::~Coin_2()
{
}

Coin_3::Coin_3():Coin_0(3)
{
    Coin_0::mType = 3;
    setFrameRect(cocos2d::Size(107,116));
}

Coin_3::~Coin_3()
{

}

Coin_4::Coin_4():Coin_0(4){
    coin_4_IsCreated = true;
    Coin_0::mType = 4;
    setFrameRect(cocos2d::Size(116,120));

}

Coin_4::~Coin_4()
{

}

Coin_5::Coin_5():Coin_0(5)
{
    Coin_0::mType = 5;
    setFrameRect(cocos2d::Size(117,133));

}

Coin_5::~Coin_5()
{

}

Coin_6::Coin_6():Coin_0(6)
{
    Coin_0::mType = 6;
    setFrameRect(cocos2d::Size(125,136));
}

Coin_6::~Coin_6()
{

}

Coin_7::Coin_7():Coin_0(7)
{
    coin_7_IsCreated = true;
    Coin_0::mType = 7;
    setFrameRect(cocos2d::Size(107,116));

}

Coin_7::~Coin_7()
{
    setFrameRect(cocos2d::Size(135,151));

}

}
