#include"Ship.h"
#include"cocos2d.h"
#include"Model.h"
#include"define.h"
Ship::Ship(cocos2d::Scene * scene) :Model()
{
	mSprite = cocos2d::Sprite::create(SHIP_IMG);
	scene->addChild(mSprite);
	mUp = true;
	mLeft = false;
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan= CC_CALLBACK_2(Ship::onTouchBegan, this);
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);
	
	for (int i = 0; i < 10; i++)
	{
		auto b = new Bullet(scene);
		b->Init();
		listBullet.push_back(b);
	}

}

Ship::~Ship()
{

}


void Ship::Update()
{
	if (mUp) {
		mSprite->setPosition(cocos2d::Vec2(GetLocation().x, GetLocation().y + SHIP_SPEED));
		if (GetLocation().y == SCREEN_H)
		{
			mUp = false;
		}
	}
	else
	{
		mSprite->setPosition(cocos2d::Vec2(GetLocation().x, GetLocation().y - SHIP_SPEED));
		if (GetLocation().y == 0)
		{
			mUp = true;
		}
	}
	for (int i = 0; i < listBullet.size(); i++)
	{
		if (!listBullet.at(i)->IsVisible()) {
			listBullet.at(i)->UpdateLocation(Vec2(GetPosition() + Vec2(10, 0)));
		}
		if (!mLeft)
		{

			listBullet.at(i)->ShootRight();
		}
		
		else
		{
			listBullet.at(i)->ShootLeft();
		}

	}



	mFrameBullet++;
	if (mFrameBullet % 4 == 0) {
		for (int i = 0; i < listBullet.size(); i++) {
			if (!listBullet.at(i)->IsVisible()) {
				listBullet.at(i)->Init();
				listBullet.at(i)->SetVisible(true);
				break;
			}
		}
	}
}

void Ship::Init()
{

	this->GetSprite()->setScale(SHIP_SCALE);
	this->SetPosition(cocos2d::Vec2(SCREEN_W / 2, SCREEN_H / 2));

}

bool Ship::onTouchBegan(Touch * touch, Event * event)
{
	auto mLocation = touch->getLocation();
	if (mLocation.x > SCREEN_W / 2)
	{
		mLeft = false;
		
	}
	else
	{
		mLeft = true;
		
	}
	mSprite->setFlipX(mLeft);

	return true;
}

void Ship::onTouchMoved(Touch * touch, Event * event)
{
}

void Ship::onTouchEnded(Touch * touch, Event * event)
{
}

