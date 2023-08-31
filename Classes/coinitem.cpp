#include "coinitem.h"

namespace CoinSpace {


    CoinItem::CoinItem(){}


    CoinItem::CoinItem(int type)
    {
        setDefaultImage(type);
    }

    bool CoinItem::onTouchBegan(Touch *touch)
    {
        initialpos = touch->getLocation();
         return true;
    }

    void CoinItem::onTouchEnded(Touch *touch)
    {
       initialpos = touch->getLocation();
    }

    void CoinItem::onTouchMoved(Touch *touch)
    {
        targetPosition = touch->getLocation();
        // Clamp new position to visible bounds
        auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
        targetPosition.x = std::min(visibleSize.width-100, std::max(0.f, targetPosition.x));
        targetPosition.y = std::min(visibleSize.height-100, std::max(0.f, targetPosition.y));

        // Update position, clamped to bounds
        this->setPosition(targetPosition);
    }

    CoinItem::~CoinItem() {}

    void CoinItem::setDefaultImage( int type)
    {
        this->setTexture(("new/coins_" + std::to_string(type) + ".png"));
    }

    short CoinItem::type() const
    {
        return mType;
    }

    Coin_0::Coin_0():CoinItem(0)
    {
        mType = 0;
        CoinItem::mType = 0;
    }

    Coin_0::~Coin_0() {}

    Coin_1::Coin_1():CoinItem(1)
    {
        CoinItem::mType = 1;
    }

    Coin_1::~Coin_1() {}

    Coin_2::Coin_2():CoinItem(2)
    {
        CoinItem::mType = 2;
    }

    Coin_2::~Coin_2() {}

    Coin_3::Coin_3():CoinItem(3)
    {
        CoinItem::mType = 3;
    }

    Coin_3::~Coin_3() {}

    Coin_4::Coin_4():CoinItem(4){
        coin_4_IsCreated = true;

        if(coin_7_IsCreated)
            exit(0);

        CoinItem::mType = 4;
    }

    Coin_4::~Coin_4() {}

    Coin_5::Coin_5():CoinItem(5)
    {
        CoinItem::mType = 5;
    }

    Coin_5::~Coin_5() {}

    Coin_6::Coin_6():CoinItem(6)
    {
        CoinItem::mType = 6;
    }

    Coin_6::~Coin_6() {}

    Coin_7::Coin_7():CoinItem(7)
    {
        coin_7_IsCreated = true;

        if(coin_4_IsCreated)
            exit(0);

        CoinItem::mType = 7;
    }

    Coin_7::~Coin_7(){}

}
