/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"

USING_NS_CC;

GameScene::GameScene()
{
    coinQuantityOnStart = 6;
   // Coins.reserve(coinQuantityOnStart + 10);
}

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

// Print useful error message instead of segfaulting
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GameScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    Sprite *sprite = Sprite::create( SCENE_BACKGROUND_FILEPATH );
    sprite->setPosition( Vec2( Director::getInstance( )->getVisibleSize( ).width / 2 + Director::getInstance( )->getVisibleOrigin( ).x, Director::getInstance( )->getVisibleSize( ).height / 2 + Director::getInstance( )->getVisibleOrigin( ).y ) );
    sprite->setScale(2.26f,2.9f);
    this->addChild( sprite );

    int coinType = 0;

    for(size_t i = 0; i < coinQuantityOnStart;++i){
        if(i>2 && coinType == 0 )
        {
            coinType = 5;
        }

        auto coinEntity = MakeRandomlyPlacedCoin(coinType);
        Coins[coinType].push_back(coinEntity);
        this->addChild(coinEntity);
    }

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_1(GameScene::onTouchEnded, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}


void GameScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
}

bool GameScene::onTouchBegan(Touch *touch, Event *event)
{
    event->stopPropagation();
    for(int i = 0; i<=7;++i){
        if(Coins[i].empty())
            continue;

        for (auto coin : Coins[i]) {
            if (coin->getBoundingBox().containsPoint(touch->getLocation())) {
                // Handle the touch event for the specific coin
                coin->onTouchBegan(touch, event);
                selectedCoin = coin;
            }
        }
    }

    return true;
}

void GameScene::onTouchEnded(Touch *touch)
{
    std::set<std::array<CoinSpace::CoinItem*, 3>> overlappingCombos;
    int selectedType = selectedCoin->type();

    for (size_t i = 0; i < Coins[selectedType].size() - 2; i++) {
        for (size_t j = i + 1; j < Coins[selectedType].size() - 1; j++) {
            for (size_t k = j + 1; k < Coins[selectedType].size(); k++) {
                std::array<CoinSpace::CoinItem*, 3> combo = {
                    Coins[selectedType][i],
                    Coins[selectedType][j], Coins[selectedType][k]};
//                std::sort(combo.begin(), combo.end());

                if (overlappingCombos.find(combo) != overlappingCombos.end()) {
                    continue; // Skip this combination, it has already been checked
                }

                if(CoinsAreOverlap(combo)){
                    break;
                }
            }
        }
    }

}

void GameScene::onTouchMoved(Touch *touch, Event *event)
{
//    touch->setTouchInfo(4,0.0f,0.0f,4.2f,9.0f);
//    touch->retain();
    selectedCoin->onTouchMoved(touch,event);
}

CoinSpace::CoinItem *GameScene::MakeRandomlyPlacedCoin(int type)
{
    int x_random, y_random;
    x_random = cocos2d::RandomHelper::random_int(0,int(Director::getInstance()->getVisibleSize().width - 300));
    y_random = cocos2d::RandomHelper::random_int(0,int(Director::getInstance()->getVisibleSize().height- 300));
    auto coinEntity = CoinSpace::CoinFactory::CreateCoin(type);
    coinEntity->setPosition(x_random,y_random);
    return coinEntity;

}

bool GameScene::CoinsAreOverlap(std::array<CoinSpace::CoinItem *,3>coins)
{
    auto box1 = coins[0]->getBoundingBox();
    auto box2 = coins[1]->getBoundingBox();
    auto box3 = coins[2]->getBoundingBox();
    float epsilon = 140.0f;
    bool overlap12 = false,overlap13 = false,overlap23 = false;
    if (box1.intersectsRect(box2) &&
        box2.intersectsRect(box3) &&
        box3.intersectsRect(box1)) {

        if (abs(box1.getMaxX() - box2.getMinX()) < epsilon) {
            overlap12 = true;
        }
//        CCLOG("%f \n",abs(box1.getMaxX() - box2.getMinX()));

        // Check box1 and box3
        if (abs(box1.getMaxX() - box3.getMinX()) < epsilon) {
            overlap13 = true;

        }
//        CCLOG("%f \n",abs(box1.getMaxX() - box3.getMinX()));
        if (abs(box2.getMaxX() - box3.getMinX()) < epsilon) {
            overlap23 = true;
        }
//        CCLOG("%f \n",abs(box2.getMaxX() - box3.getMinX()));
        // See if all overlaps occurred
        if (overlap12 && overlap13 && overlap23) {
            // All boxes overlap
                CCLOG("Are overlap");
                return true;
        }
    }
    return false;
}
