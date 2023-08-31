#ifndef COINITEM_H
#define COINITEM_H

#include "Definitions.h"

#include <cstdlib>
#include <string>

namespace CoinSpace{

    class CoinItem;
    class Coin_0;
    class Coin_1;
    class Coin_2;
    class Coin_3;
    class Coin_4;
    class Coin_5;
    class Coin_6;
    class Coin_7;

    static bool coin_4_IsCreated = false ,coin_7_IsCreated = false;

    class CoinItem: public cocos2d::Sprite
    {
    public:
        CoinItem();
        CoinItem(int type);

        virtual bool onTouchBegan(Touch* touch) ;
        virtual void onTouchMoved(Touch* touch) ;
        virtual void onTouchEnded(Touch* touch) ;

        virtual ~CoinItem();
        short type() const;
    protected:
        cocos2d::Vec2 targetPosition, initialpos;
        void setDefaultImage(int type);
        float heightRect, widthRect;
        short mType;
    };

    class Coin_0 : public CoinItem{
    public:
        Coin_0();
        virtual ~Coin_0();
    };

    class Coin_1 : public CoinItem{
    public:
        Coin_1();
        virtual ~Coin_1();
    };

    class Coin_2 : public CoinItem{
    public:
        Coin_2();
        virtual ~Coin_2();
    };

    class Coin_3 : public CoinItem{
    public:
        Coin_3();
        virtual ~Coin_3();
    };

    class Coin_4 : public CoinItem{
    public:
        Coin_4();
        virtual ~Coin_4();
    };

    class Coin_5 : public CoinItem{
    public:
        Coin_5();
        virtual ~Coin_5();
    };

    class Coin_6 : public CoinItem{
    public:
        Coin_6();
        virtual ~Coin_6();
    };

    class Coin_7 : public CoinItem{
    public:
        Coin_7();
        virtual ~Coin_7();
    };

}
#endif // COINITEM_H
