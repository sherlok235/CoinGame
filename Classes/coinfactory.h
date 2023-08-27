#ifndef COINSPACE_COINFACTORY_H
#define COINSPACE_COINFACTORY_H

#include "coinitem.h"

namespace CoinSpace {

    class CoinFactory
    {
    public:
        CoinFactory();
        static CoinItem * CreateCoin(int type);
    };

} // namespace CoinSpace

#endif // COINSPACE_COINFACTORY_H
