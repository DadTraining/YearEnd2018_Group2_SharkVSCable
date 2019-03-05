#include "GamePlayScene.h"
#include "SimpleAudioEngine.h"
#include "PopUpShop.h"
#include "PopUpSetting.h"
#include "define.h"
#include "ui\CocosGUI.h"
#include"Model.h"
#include"MapScene.h"




//PopUpShop::PopUpShop(cocos2d::Scene * createScene)
//{
//	// layer 
//	mLayer = cocos2d::Layer::create();
//	mLayer->setAnchorPoint(cocos2d::Vec2(0.5, 0.5));
//	mLayer->setPosition(SCREEN_W /200, SCREEN_H / 200);
//	createScene->addChild(mLayer);
//}

bool PopUpShop::init()
{
	if (!Node::init()) return false;

	visibleSize = Director::getInstance()->getVisibleSize();

	mLayer = cocos2d::Layer::create();
	//mLayer->setAnchorPoint(cocos2d::Vec2(0, 0));
	mLayer->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(mLayer);

	
	setBackground();
	return true;
}

void PopUpShop::onExit()
{
	Node::onExit();
}

void PopUpShop::setBackground()
{
	// backgroud
	mBackground = Sprite::create(BACKGROUNDSHOP);
	mBackground->setPosition(cocos2d::Vec2::ZERO);
	mLayer->addChild(mBackground, -1);

	//button exit
	auto btnExitShop = cocos2d::ui::Button::create(BUTTON_EXIT);
	btnExitShop->setPosition(cocos2d::Vec2(mBackground->getContentSize().width / 2 - 20,
		mBackground->getContentSize().height / 2 - 30));
	btnExitShop->setScale(0.5);
	btnExitShop->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType touch) {
		switch (touch)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:

			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			HandlTouch();
			break;

		}
	});
	mLayer->addChild(btnExitShop);

	// lable stun
	TTFConfig labelConfig;
	labelConfig.fontFilePath = FONT_SCORE;
	labelConfig.fontSize = 31;
	labelConfig.glyphs = GlyphCollection::DYNAMIC;
	labelConfig.outlineSize = 2;
	labelConfig.customGlyphs = nullptr;
	labelConfig.distanceFieldEnabled = false;

	mStun = 111;
	
	auto mLableStun = Label::createWithTTF(labelConfig, std::to_string(mStun));
	mLableStun->setPosition(cocos2d::Vec2( mBackground->getContentSize().width*0.25 , mBackground->getContentSize().height*0.65));
	mLableStun->enableGlow(Color4B::BLUE);
	mLableStun->setColor(Color3B::YELLOW);	
    mBackground->addChild(mLableStun);

	//lable health	
	mHealth = 111;
	auto mLableHealth = Label::createWithTTF(labelConfig, std::to_string(mHealth));
	mLableHealth->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.5, mBackground->getContentSize().height*0.65));
	mLableHealth->enableGlow(Color4B::BLUE);
	mLableHealth->setColor(Color3B::YELLOW);
	mBackground->addChild(mLableHealth);

	//lable electic gun
	mElection = 111;
	auto mLableGun = Label::createWithTTF(labelConfig, std::to_string(mElection));
	mLableGun->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.75, mBackground->getContentSize().height*0.65));
	mLableGun->enableGlow(Color4B::BLUE);
	mLableGun->setColor(Color3B::YELLOW);
	mBackground->addChild(mLableGun);


	// icon stun
	auto mIconStun = Sprite::create(ITEM_BRICK_IMAGE);
	mIconStun->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.25, mBackground->getContentSize().height*0.45));
	mBackground->addChild(mIconStun);
	// icon health
	auto mIconHealth = Sprite::create(ITEM_HP_IMAGE);
	mIconHealth->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.5, mBackground->getContentSize().height*0.45));
	mIconHealth->setScale(0.85);
	mBackground->addChild(mIconHealth);
	//icon electric gun
	auto mIconGun = Sprite::create(ITEM_BOOM_IMAGE);
	mIconGun->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.75, mBackground->getContentSize().height*0.45));
	mBackground->addChild(mIconGun);

	// button buy Stun	
	auto btnBuyStun = cocos2d::ui::Button::create(BUTTON_BUY);
	btnBuyStun->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.25,
		mBackground->getContentSize().height *0.26));	
	btnBuyStun->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType touch) {
		switch (touch)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:			
			break;

		}
	});
	mBackground->addChild(btnBuyStun);

	//button buy Health
	auto btnBuyHealth = cocos2d::ui::Button::create(BUTTON_BUY);
	btnBuyHealth->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.5,
		mBackground->getContentSize().height *0.26));
	btnBuyHealth->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType touch) {
		switch (touch)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;

		}
	});
	mBackground->addChild(btnBuyHealth);

	// button buy electric gun

	auto btnBuyGun = cocos2d::ui::Button::create(BUTTON_BUY);
	btnBuyGun->setPosition(cocos2d::Vec2(mBackground->getContentSize().width*0.75,
		mBackground->getContentSize().height *0.26));
	btnBuyGun->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType touch) {
		switch (touch)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			break;

		}
	});
	mBackground->addChild(btnBuyGun);
}

void PopUpShop::disappear()
{

}

cocos2d::Layer * PopUpShop::getLayer()
{
	return mLayer;
}

void PopUpShop::HandlTouch()
{
	mLayer->setVisible(false);
	cocos2d::Director::getInstance()->resume();
}





