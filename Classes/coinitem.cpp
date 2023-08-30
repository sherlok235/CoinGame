#include "coinitem.h"

namespace CoinSpace {


Coin_0::Coin_0():CoinItem(0)
{
    mType = 0;
    setContentSize(cocos2d::Size(65,65));
    CoinItem::mType = 0;
//    if(coin_4_IsCreated && coin_7_IsCreated)
//        exit(0);
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
//   this->getPhysicsBody()
   this->getPhysicsBody()->createCircle(10);
//   touch->setTouchInfo(0,touch->getLocation().y,touch->getLocation().x,0,100);
    targetPosition = touch->getLocation();
//    auto currentPos = initialpos;

    auto direction = targetPosition - initialpos;

    //  Optimize it
    auto newPos = initialpos + direction;

    // Clamp new position to visible bounds
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    newPos.x = std::min(visibleSize.width-100, std::max(0.f, newPos.x));
    newPos.y = std::min(visibleSize.height-100, std::max(0.f, newPos.y));

    // Update position, clamped to bounds
    this->setPosition(newPos);
}

CoinItem::~CoinItem()
{

}

void CoinItem::setDefaultImage( int type)
{
    this->setTexture(("new/coins_" + std::to_string(type) + ".png"));
}

short CoinItem::type() const
{
    return mType;
}


void CoinItem::setHeightRect(float newHeightRect)
{
    heightRect = newHeightRect;
}

void CoinItem::setContentSize(cocos2d::Size size)
{
    auto frame = new cocos2d::SpriteFrame();
    frame->setRect(cocos2d::Rect(this->getPosition(),cocos2d::Size(size.width,size.height)));
    this->createWithSpriteFrame(frame);
}

bool CoinItem::operator<(CoinItem *other)
{
    return this->getPosition() < other->getPosition();
}

void CoinItem::setWidthRect(float newWidthRect)
{
    widthRect = newWidthRect;
}

Coin_1::Coin_1():CoinItem(1)
{
    CoinItem::mType = 1;
    setContentSize(cocos2d::Size(86,92));
}

Coin_1::~Coin_1()
{

}

Coin_2::Coin_2():CoinItem(2)
{
    CoinItem::mType = 2;
    setContentSize(cocos2d::Size(92,100));
}

Coin_2::~Coin_2()
{
}

Coin_3::Coin_3():CoinItem(3)
{
    CoinItem::mType = 3;
    setContentSize(cocos2d::Size(107,116));
}

Coin_3::~Coin_3()
{

}

Coin_4::Coin_4():CoinItem(4){
    coin_4_IsCreated = true;
    if(coin_7_IsCreated)
        exit(0);
    CoinItem::mType = 4;
    setContentSize(cocos2d::Size(116,120));

}

Coin_4::~Coin_4()
{

}

Coin_5::Coin_5():CoinItem(5)
{
    CoinItem::mType = 5;
    setContentSize(cocos2d::Size(117,133));

}

Coin_5::~Coin_5()
{

}

Coin_6::Coin_6():CoinItem(6)
{
    CoinItem::mType = 6;
    setContentSize(cocos2d::Size(125,136));
}

Coin_6::~Coin_6()
{

}

Coin_7::Coin_7():CoinItem(7)
{
    coin_7_IsCreated = true;
    if(coin_4_IsCreated)
        exit(0);
    CoinItem::mType = 7;
    setContentSize(cocos2d::Size(107,116));

}

Coin_7::~Coin_7()
{
    setContentSize(cocos2d::Size(135,151));

}

}
