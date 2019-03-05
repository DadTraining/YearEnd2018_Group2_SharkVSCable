#include "IntroScene.h"
#include "MapScene.h"
#include "define.h"
#include "ui\CocosGUI.h"
#include "Shark.h"
#include "MapLevel.h"
#include "InfoMap.h"
#include "Constants.h"



USING_NS_CC;


Scene* IntroScene::createScene()
{
	return IntroScene::create();
}

// on "init" you need to initialize your instance
bool IntroScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Page();
	Loading();
	BGMusic();
	LoadGame();
	AddDataBase();
	return true;
}

/*Creat PageView to show guidance*/
void IntroScene::Page()
{
	auto pageView = ui::PageView::create();
	pageView->setContentSize(Size(visibleSize.width, visibleSize.height));
	pageView->setBounceEnabled(true);
	pageView->setTouchEnabled(true);
	pageView->setAnchorPoint(Vec2(0.5, 0.5));
	pageView->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 + visibleSize.height / 7));
	this->addChild(pageView);

	for (int i = 1; i < 4; i++)
	{
		char normal[20] = { 0 };
		sprintf(normal, "intro/%d.png", i);
		auto layout = ui::Layout::create();
		layout->setContentSize(pageView->getContentSize());
	    auto sprite = Sprite::create(normal);
		sprite->setPosition(Vec2(layout->getSize().width / 2, layout->getSize().height / 2));
		layout->addChild(sprite);
		pageView->addPage(layout);

	}
    pageView->scrollToItem(3);

}

/*Creat Background Music*/
void IntroScene::BGMusic()
{
	audio = CocosDenshion::SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic(MUSIC_BACKGROUND, true);

}

void IntroScene::AddDataBase()
{
	sqlite3* _database;
	std::string _path = FileUtils::getInstance()->getWritablePath() + DATA_BASE_NAME;

	if (sqlite3_open(_path.c_str(), &_database) != SQLITE_OK)
	{
		sqlite3_close(_database);
		CCLOG("IntroScene::AddDataBase::OPEN_FAIL");
	}
	else
	{
		int result = sqlite3_exec(_database,
			"create table tbMapLevel(id integer primary key autoincrement, lv integer,star integer,p1 integer,p2 integer,p3 integer,skin integer,score integer,pass boolean,allowplay boolean)"
			, nullptr, nullptr, nullptr);

		if (result !=0)
		{
			CCLOG("IntroScene::AddDataBase::CREATE_FAIL");
		}
		else
		{
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,1,0,3,5,7,0,0,'false','true')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,2,0,4,6,8,0,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,3,0,5,7,9,0,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,4,0,5,7,9,4,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,5,0,5,7,9,5,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,6,0,5,7,9,6,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,7,0,5,7,9,7,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,8,0,6,8,10,5,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,9,0,6,8,10,6,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,10,0,6,8,10,7,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,11,0,6,8,10,8,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,12,0,6,8,10,9,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,13,0,7,9,11,4,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,14,0,7,9,11,5,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,15,0,7,9,11,6,0,'false','false')"
				, nullptr, nullptr, nullptr);
			sqlite3_exec(_database,
				"insert into tbMapLevel values (null,16,0,7,9,11,7,0,'false','false')"
				, nullptr, nullptr, nullptr);

		}
	}

}

void IntroScene::LoadGame()
{
	MapLevel *m1 = new MapLevel(1, 0, 3, 5, 7, 0, false, 0, true);
	Constants::AddMapIntoList(m1);
	MapLevel *m2 = new MapLevel(2, 0, 4, 6, 8, 0, false, 0, false);
	Constants::AddMapIntoList(m2);
	MapLevel *m3 = new MapLevel(3, 0, 5, 7, 9, 1, false, 0, false);
	Constants::AddMapIntoList(m3);
	MapLevel *m4 = new MapLevel(4, 0, 4, 6, 8, 2, false, 0, false);
	Constants::AddMapIntoList(m4);
	MapLevel *m5 = new MapLevel(5, 0, 5, 7, 9, 3, false, 0, false);
	Constants::AddMapIntoList(m5);
	MapLevel *m6 = new MapLevel(6, 0, 5, 7, 9, 4, false, 0, false);
	Constants::AddMapIntoList(m6);
	MapLevel *m7 = new MapLevel(7, 0, 5, 7, 9, 5, false, 0, false);
	Constants::AddMapIntoList(m7);
	MapLevel *m8 = new MapLevel(8, 0, 6, 8, 10, 3, false, 0, false);
	Constants::AddMapIntoList(m8);
	MapLevel *m9 = new MapLevel(9, 0, 6, 8, 10, 4, false, 0, false);
	Constants::AddMapIntoList(m9);
	MapLevel *m10 = new MapLevel(10, 0, 6, 8, 10, 5, false, 0, false);
	Constants::AddMapIntoList(m10);
	MapLevel *m11 = new MapLevel(11, 0, 6, 8, 10, 6, false, 0, false);
	Constants::AddMapIntoList(m11);
	MapLevel *m12 = new MapLevel(12, 0, 6, 8, 10, 7, false, 0, false);
	Constants::AddMapIntoList(m12);
	MapLevel *m13 = new MapLevel(13, 0, 6, 8, 10, 8, false, 0, false);
	Constants::AddMapIntoList(m13);
	MapLevel *m14 = new MapLevel(14, 0, 6, 8, 10, 9, false, 0, false);
	Constants::AddMapIntoList(m14);
	MapLevel *m15 = new MapLevel(15, 0, 6, 8, 10, 10, false, 0, false);
	Constants::AddMapIntoList(m15);
	MapLevel *m16 = new MapLevel(16, 0, 6, 8, 10, 11, false, 0, false);
	Constants::AddMapIntoList(m16);

}

/*Create LoadingBar*/
void IntroScene::Loading()
{
	static auto loadingBarBG = Sprite::create(LOADING_BAR_BACKGROUND);
	loadingBarBG->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 7));
	loadingBarBG->setVisible(true);
	addChild(loadingBarBG, 2);

	static auto loadingBar = ui::LoadingBar::create(LOADING_BAR);
	loadingBar->setPercent(0);
	loadingBar->setDirection(ui::LoadingBar::Direction::LEFT);
	loadingBar->setPosition(loadingBarBG->getPosition());
	loadingBar->setVisible(true);
	addChild(loadingBar, 2);

	//////////////
	//button play
	static auto button = ui::Button::create(BUTTON_PLAY);
	button->setPosition(loadingBar->getPosition());

	button->setVisible(false);
	this->addChild(button, 3);
	loadingBar->setPercent(70);
	auto updateLoadingBar = CallFunc::create([=]() {
		if (loadingBar->getPercent() < 100)
		{
			loadingBar->setPercent(loadingBar->getPercent() + 1);
		}

		if (loadingBar->getPercent() == 100)
		{
			loadingBarBG->setVisible(false);
			loadingBar->setVisible(false);

			//////////////////////
			//button play appear when loading finish
			button->setVisible(true);
			button->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
				switch (type)
				{
				case ui::Widget::TouchEventType::BEGAN:
					break;
				case ui::Widget::TouchEventType::ENDED:
				{
					audio->stopBackgroundMusic();
					Director::getInstance()->replaceScene(TransitionFadeTR::create(1, MapScene::createScene()));
					break;
				}

				default:
					break;
				}
			});
		}
	});

	auto sequenceRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeatLoad = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingBar->runAction(repeatLoad);

}





