#pragma once
#include "../Input/Controller.h"
#include "../SSPlayer/SS5Player.h"
#include "../Enemy/Enemy.h"
#include "../HitBox/HitBox.h"

class Enemy;

/*
プレイヤーを制御するクラス
*/
class Player {
public:
	inline int getPositionX() { return mPositionX; }
	inline int getPositionY() { return mPositionY; }
	inline int getState() { return mState; }
	inline int getCatchId() { return mCatchId; }
	inline HitBox getHitBox() { return mHitBox; }
	inline int getBoltBreakCounter() { return mBoltBreakCounter; }
	inline ss::Player* getSprite() { return mSprite; }
	inline Controller getController() { return mController; }

	inline void setAcceleX(int acceleX) { mAcceleX = acceleX; }

	void Load();
	void Move(int &state, Enemy& enemy);
	void DoJump();
	void CheckWallHit();
	void Catch();
	void Catching();
	void Damaged();
	void Riding();
	void UpdateAnimation();

	void Draw();

private:
	Controller mController;
	Enemy *mEnemy;
	int mGraph;

	int mBoltBreakCounter;
	int mAnimationCounter;
	int mState;
	bool mRight;
	float mCatchRad;
	float mCatchId;
	float mCatchLength;
	int mDamageCounter;
	int mPositionX;
	int mPositionY;
	double mPositionDX;
	double mPositionDY;
	HitBox mHitBox;
	int mAcceleX;
	int mAcceleY;
	bool mCatching;
	bool mGround;
	ss::Player *mSprite;

	int mAnimeFire;
	int mAnimeFireKey;
	int mAnimeCatch;
	int mAnimeCatchKey;

	int mGraphShadow;
	int mGraphStopper;

	int mGraphBreak1;
	int mGraphBreak2;
	int mGraphBreakL;
	int mGraphBreakR;
	int mGraphRepair1;
	int mGraphRepair2;
	int mGraphBreakdown1;
	int mGraphBreakdown2;
	int mGraphBreakdownL;
	int mGraphBreakdownR;

	int mSoundDamage;
	int mSoundCatch;
	int mSoundStep;
	int mSoundJump;
	int mSoundLand;
	int mSoundBreakBolt;
};