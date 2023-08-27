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
        virtual bool onTouchBegan(Touch* touch, Event* event) ;
        virtual void onTouchEnded(Touch* touch, Event* event) ;
        virtual void onTouchMoved(Touch* touch, Event* event) ;
        void moveToTarget();

        void setWidthRect(float newWidthRect);
        void setHeightRect(float newHeightRect);
        void setFrameRect(cocos2d::Size size);
        virtual ~CoinItem();
    protected:
        cocos2d::Vec2 targetPosition, initialpos;
        void setDefaultImage(int type);
        float heightRect, widthRect;
        bool temp;
    };

    class Coin_0 : public CoinItem{
    public:
        Coin_0();
        Coin_0(int);
        int getType() const;
        void setType(short type);
        virtual ~Coin_0();

    protected:
        int mType;
    };

    class Coin_1 : public Coin_0{
    public:
        Coin_1();
        virtual ~Coin_1();
    };

    class Coin_2 : public Coin_0{
    public:
        Coin_2();
        virtual ~Coin_2();
    };

    class Coin_3 : public Coin_0{
    public:
        Coin_3();
        virtual ~Coin_3();
    };

    class Coin_4 : public Coin_0{
    public:
        Coin_4();
        virtual ~Coin_4();
    };

    class Coin_5 : public Coin_0{
    public:
        Coin_5();
        virtual ~Coin_5();
    };

    class Coin_6 : public Coin_0{
    public:
        Coin_6();
        virtual ~Coin_6();
    };

    class Coin_7 : public Coin_0{
    public:
        Coin_7();
        virtual ~Coin_7();
    };

}
#endif // COINITEM_H
