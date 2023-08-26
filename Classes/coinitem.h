#ifndef COINITEM_H
#define COINITEM_H
#include "cocos2d.h"
#include <cstdlib>
#include <string>

namespace CoinSpace{

class Coin_0;
class Coin_1;
class Coin_2;
class Coin_3;
class Coin_4;
class Coin_5;
class Coin_6;
class Coin_7;

static bool coin_4_IsCreated=false ,coin_7_IsCreated =false;

class CoinItem:public cocos2d::Sprite
{
public:
    CoinItem();
    CoinItem(int type);
//    static CoinItem* create(short type);
protected:
    void setDefaultImage(int type) ;
};

class Coin_0 : public CoinItem{
public:
    Coin_0();
    Coin_0(int);
    int getType() const;
    void setType(short type);
protected:
    int mType;

};

class Coin_1 : public Coin_0{
public:
    Coin_1();
};

class Coin_2 : public Coin_0{
public:
    Coin_2();
};

class Coin_3 : public Coin_0{
public:
    Coin_3();
};

class Coin_4 : public Coin_0{
public:
    Coin_4();
};

class Coin_5 : public Coin_0{
public:
    Coin_5();
};

class Coin_6 : public Coin_0{
public:
    Coin_6();
};

class Coin_7 : public Coin_0{
public:
    Coin_7();
};
}
#endif // COINITEM_H
