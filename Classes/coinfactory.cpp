#include "coinfactory.h"

namespace CoinSpace {

    CoinFactory::CoinFactory()
    {

    }

    CoinItem *CoinFactory::CreateCoin(int type)
    {
        switch(type){
            case 0:
                return new CoinSpace::Coin_0();
            break;
            case 1:
                return new CoinSpace::Coin_1();
            break;
            case 2:
                return new CoinSpace::Coin_2();
            break;
            case 3:
                return new CoinSpace::Coin_3();
            break;
            case 4:
                return new CoinSpace::Coin_4();
            break;
            case 5:
                return new CoinSpace::Coin_5();
            break;
            case 6:
                return new CoinSpace::Coin_6();
            break;
            case 7:
                return new CoinSpace::Coin_7();
            break;
            default:
                return nullptr;
            break;

        }
    }

} // namespace CoinSpace
