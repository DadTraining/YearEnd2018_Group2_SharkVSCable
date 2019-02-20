#pragma once
#include "cocos2d.h"
#include "Model.h"

class Shark : public Model
{
protected:
	float mSize;
	float mDelay;
	bool mMoveToLeft;
	std::string mColor;
	int mTotalColor;
	float mSpeed;
	int mDamage;
	std::string mStatus;
	std::string mOldStatus;

public:
	Shark();
	Shark(cocos2d::Scene* scene);
	Shark(const Shark * shark);
	virtual ~Shark();

	void Damaged();
	void Killed();
	void Angry();
	void Normal();
	void RunAway();
	void ChangeDirection();
	void Clone();
	void BiteAnimation();
	void SwimAnimation();
	void Move();
	void UnMove(cocos2d::Vec2 pos);
	void RunAwayAnimation();

	virtual void Update();
	void UnUpdate(cocos2d::Vec2 pos);
	virtual void Init();
	void SetStatus(std::string status) {
		this->mStatus= status;
	}

	void SetOldStatus() {
		mStatus = mOldStatus;
	}

};

