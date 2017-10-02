#pragma once
#include "../SSPlayer/SS5Player.h"
#include "../Quad/Quad.h"
#include "../Player/Player.h"
#include "Bullet.h"

class Player;

/*
ìGÇêßå‰Ç∑ÇÈÉNÉâÉX
*/
class Enemy {
public:
	inline int getPositionX() { return mPositionX; }
	inline int getPositionY() { return mPositionY; }
	inline int getNumHit() { return numHit; }
	inline int getNumBolt() { return numBolt; }
	inline int getNumCore() { return numCore; }
	inline int getHitExist(int n) { return mHitExist[n]; }
	inline int getBoltExist(int n) { return mBoltExist[n]; }
	inline int getCoreExist(int n) { return mCoreExist[n]; }

	Quad getQuad(const char* name);
	inline ss::Player getSprite() { return *mSprite; }

	virtual void Load();
	virtual void LoadGraphic();
	virtual void Process(int& state,Player &player);
	virtual void CheckBulletHit(Player &player);
	virtual void BrokenBolt(int id);
	virtual void BrokenCore(int id);
	virtual void Draw(Player &player);
	virtual void DrawBullet(){}

protected:
	
	int mPositionX;
	int mPositionY;
	ss::Player *mSprite;

	int mShotCounter;
	Bullet mBullet;

	bool mCoreExist[10];
	bool mBoltExist[20];
	bool mHitExist[20];
	int numCore;
	int numBolt;
	int numHit;
	int mState;

	int mGraphBolt;
	int mGraphCore;

	int mVoiceBroken;
	int mSoundBroken;
	int mSoundBlood;
	int mSoundBreath;
	
	int mBGM;
};