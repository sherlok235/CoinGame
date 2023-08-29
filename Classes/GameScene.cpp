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
    //Coins.reserve(coinQuantityOnStart + 10);
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

    int coinType = 0, x_random, y_random;

    for(size_t i = 0; i < coinQuantityOnStart;++i){
        if(i>2 && coinType == 0 )
        {
            coinType = 5;
        }
        x_random = cocos2d::RandomHelper::random_int(0,int(Director::getInstance()->getVisibleSize().width - 300));
        y_random = cocos2d::RandomHelper::random_int(0,int(Director::getInstance()->getVisibleSize().height- 300));
        auto coinEntity = CoinSpace::CoinFactory::CreateCoin(coinType);
        coinEntity->setPosition(x_random,y_random);
        Coins.insert(coinEntity);
        this->addChild(coinEntity);
    }

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
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
    for (auto coin : Coins) {
        if (coin->getBoundingBox().containsPoint(touch->getLocation())) {
            // Handle the touch event for the specific coin
            coin->onTouchBegan(touch, event);
            selectedCoin = coin;
        }
    }

    return true;
}

void GameScene::onTouchEnded(Touch *touch, Event *event)
{
   // CCLOG("%f,%f",selectedCoin->getPositionX(), selectedCoin->getPositionY());
     auto start = Coins.begin(),Temp =Coins.begin(),end = Coins.end();
    std::array<CoinSpace::CoinItem*, 3> temp;
     CoinSpace::CoinItem* buff = nullptr;
    for (auto i = 0; i != (Coins.size() - 3); ++i) {
        Temp = start;
        if(Temp != end){
            temp[0] = (*start);
            buff = temp[1];
            Temp = std::next(start);

            if(Temp != end){
                temp[1] = (*Temp);
                Temp = std::next(start, 2);

                if(Temp != end){
                    temp[2] = (*Temp);
                }else{
                    temp[2] = nullptr;
                    buff = temp[1];
                    break;
                }
            }else{
                temp[1] = nullptr;
                temp[2] = nullptr;
                break;
            }
        }
        else{
            break;
        }
        std::advance(start, 2); // Move the iterator forward by 2 positions
        if(CoinsAreOverlap(temp))
            break;
    }
    if(temp[2] == nullptr && temp[1] != nullptr){
        temp[2] = buff;
        CoinsAreOverlap(temp);
    }
}

void GameScene::onTouchMoved(Touch *touch, Event *event)
{
    selectedCoin->onTouchMoved(touch,event);
}

bool GameScene::CoinsAreOverlap(std::array<CoinSpace::CoinItem *,3>coins)
{
    auto box1 = coins[0]->getBoundingBox();
    auto box2 = coins[1]->getBoundingBox();
    auto box3 = coins[2]->getBoundingBox();

    // Check overlaps
    if (box1.intersectsRect(box2) &&
        box2.intersectsRect(box3) &&
        box3.intersectsRect(box1)) {
        CCLOG("Are overlap");
        return true;
    }
    return false;
}
