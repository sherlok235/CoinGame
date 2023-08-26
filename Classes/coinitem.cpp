#include "coinitem.h"



//CoinItem *CoinSpace::CoinItem::create(short type)
//{
//    if( type > 7 )
//        return nullptr;

//    CoinItem *coin = new CoinItem();
//    std::string prefix {"coins_"}, sufix{".png"};

//    coin->setTexture((prefix + std::to_string(type) + sufix).c_str());
//    coin->setType(type);
//    coin->autorelease();

//    return coin;
//}

CoinSpace::Coin_0::Coin_0():CoinItem(0)
{
    mType = 0;
//    setDefaultImage(mType);
}

CoinSpace::Coin_0::Coin_0(int type):CoinItem(type)
{
    if(coin_4_IsCreated && coin_7_IsCreated)
        exit(0);
    mType = type;
}

int CoinSpace::Coin_0::getType() const
{
    return mType;
}

void CoinSpace::Coin_0::setType(short type)
{
    mType = type;

}

CoinSpace::CoinItem::CoinItem(int type)
{
    setDefaultImage(type);
}

void CoinSpace::CoinItem::setDefaultImage( int type)
{
    this->setTexture(("coins_" + std::to_string(type) + ".png"));
   // this->setType(type);
    this->autorelease();
}

CoinSpace::Coin_1::Coin_1():Coin_0(1)
{
    Coin_0::mType = 1;
//    setDefaultImage(mType);
}

CoinSpace::Coin_2::Coin_2():Coin_0(2)
{
    Coin_0::mType = 2;
}

CoinSpace::Coin_3::Coin_3():Coin_0(3)
{
    Coin_0::mType = 3;
}

CoinSpace::Coin_4::Coin_4():Coin_0(4){
    coin_4_IsCreated = true;
    Coin_0::mType = 4;
}

CoinSpace::Coin_5::Coin_5():Coin_0(5)
{
    Coin_0::mType = 5;
}

CoinSpace::Coin_6::Coin_6():Coin_0(6)
{
    Coin_0::mType = 6;
}

CoinSpace::Coin_7::Coin_7():Coin_0(7)
{
    coin_7_IsCreated = true;
    Coin_0::mType = 7;
}

