#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"
#include "Shark.h"
#include <vector>
#include "define.h"	
#include "Constants.h"
USING_NS_CC;


#pragma region Shark
std::vector<Shark*> sharkList;
int callBackAlive;
Shark* sk;
Item * item;

#pragma endregion


Scene* GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GamePlayScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	//Constants::setVisibleSize(visibleSize);

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto _backGround = cocos2d::Sprite::create(BACKGROUND_IMG);
	_backGround->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
	_backGround->setScaleY(Constants::getVisibleSize().height / _backGround->getContentSize().height);
	_backGround->setScaleX(Constants::getVisibleSize().width / _backGround->getContentSize().width);

	addChild(_backGround, -1);

	auto _cable = cocos2d::Sprite::create(CABLE_IMG);
	_cable->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
	_cable->setScaleY(Constants::setScaleSprite(Constants::getVisibleSize().height,1,_cable->getContentSize().height));
	addChild(_cable, 1);

	auto _btnYellow = cocos2d::Sprite::create(BUTTON_YELLOW_IMG);
	_btnYellow->setPosition(cocos2d::Vec2(visibleSize.width / 5, visibleSize.height / 7));
	_btnYellow->setScale(Constants::setScaleSprite(Constants::getVisibleSize().height, 6, _btnYellow->getContentSize().height));
	addChild(_btnYellow, 137);

	auto _btnBlue = cocos2d::Sprite::create(BUTTON_YELLOW_IMG);
	_btnBlue->setPosition(cocos2d::Vec2(visibleSize.width * 2 / 5, visibleSize.height / 7));
	_btnBlue->setScale(Constants::setScaleSprite(Constants::getVisibleSize().height, 6, _btnBlue->getContentSize().height));

	addChild(_btnBlue, 137);

	auto _btnRed = cocos2d::Sprite::create(BUTTON_YELLOW_IMG);
	_btnRed->setPosition(cocos2d::Vec2(visibleSize.width * 3 / 5, visibleSize.height / 7));
	_btnRed->setScale(Constants::setScaleSprite(Constants::getVisibleSize().height, 6, _btnRed->getContentSize().height));

	addChild(_btnRed, 137);

	auto _btnBlack = cocos2d::Sprite::create(BUTTON_YELLOW_IMG);
	_btnBlack->setPosition(cocos2d::Vec2(visibleSize.width * 4 / 5, visibleSize.height / 7));
	_btnBlack->setScale(Constants::setScaleSprite(Constants::getVisibleSize().height, 6, _btnBlack->getContentSize().height));

	addChild(_btnBlack, 137);

	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shark/sprites.plist", "shark/sprites.png");

	for (int i = 0; i < SHARK_MAX_ON_SCREEN; i++)
	{
		sharkList.push_back(new Shark(this));
	}
	//sk = new Shark(this);
	//sk->SetVisible(true);
	callBackAlive = 0;
	ship = new Ship(this);
	item = new Item(this);
	for (int i = 1; i <= 3; i++)
	{
		std::string path = "item/", png = ".png", name;
		char c = '0' + i;
		name = path + c + png;
		auto button = ui::Button::create(name);
		listItem.push_back(button);
		switch (i)
		{
		case 1:
			//button= ui::Button::create(ITEM_BRICK_IMAGE);
			
			button->setPosition(Vec2(Constants::getVisibleSize().width * 0.85, Constants::getVisibleSize().height * 0.95));
			button->setScale(ITEM_SCAlE);
			button->addClickEventListener([=](Ref* event)
			{
				item->StunShark(sharkList);

			});
			break;
		case 2:
			//button = ui::Button::create(ITEM_HP_IMAGE);
			button->setScale(ITEM_SCAlE);
			button->setPosition(Vec2(Constants::getVisibleSize().width * 0.9, Constants::getVisibleSize().height * 0.95));
			button->addClickEventListener([=](Ref* event)
			{
				item->IncreaseBlood();
				
			});
			break;
		case 3:
			//button = ui::Button::create(ITEM_BOOM_IMAGE);
			button->setScale(ITEM_SCAlE);
			button->setPosition(Vec2(Constants::getVisibleSize().width * 0.95, Constants::getVisibleSize().height * 0.95));
			button->addClickEventListener([=](Ref* event)
			{
				item->KillSharkByBoom(sharkList);
			});
			break;
		default:
			break;	
		}
		this->addChild(button);
		
	}

	this->scheduleUpdate();
	return true;
	//
}


void GamePlayScene::menuCloseCallback(Ref* pSender)
{
}

void GamePlayScene::update(float delta)
{
	//	sk->Update();
	callBackAlive += 1;
	if (callBackAlive % SHARK_CALL_BACK_ALIVE == 0)
	{
		GamePlayScene::SharkAliveCallBack();
	}

	for (int i = 0; i < sharkList.size(); i++)
	{
		if (sharkList[i]->IsVisible())
		{
			sharkList[i]->Update();
		}
		
	}
	ship->Update();
	item->Update();
}

void GamePlayScene::SharkAliveCallBack()
{
	for (int i = 0; i < sharkList.size(); i++)
	{
		auto x = sharkList[i]->SpriteIsVisible();
		if (!x)
		{
			//sharkList[i]->SetVisible(true);
			sharkList[i]->Init();
			break;
		}
	}
}
