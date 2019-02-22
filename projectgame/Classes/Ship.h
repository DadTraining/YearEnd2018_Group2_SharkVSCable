#pragma once
#include "cocos2d.h"
#include "Shark.h"
#include "Model.h"
#include "Meat.h"
#include "Bullet.h"
#include <vector>

using namespace cocos2d;
class Ship : public Model
{
private:
	bool mUp;
	bool mLeft;
	vector<Bullet*> listBullet;
	int mFrameBullet;
	

public:
	Ship(cocos2d::Scene * scene);
	~Ship();



	virtual void Update();
	virtual void Init();
	
	void leftOrRight(bool direction);
	bool getDirection();

	void ShootColor(int color);

	void Collision(std::vector<Shark*> sharks,int sharkTag,int bulletTag);

	bool GetDirection() {
		return mLeft;
	}


};