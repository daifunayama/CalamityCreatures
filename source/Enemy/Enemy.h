#pragma once
#include "../SSPlayer/SS5Player.h"
#include "../Quad/Quad.h"
#include "../Player/Player.h"

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
	inline int getHitExist(int n) { return mHitExist[n]; }
	inline int getBoltExist(int n) { return mBoltExist[n]; }

	Quad getQuad(const char* name);
	inline ss::Player getSprite() { return *mSprite; }

	virtual void Load();
	virtual void LoadGraphic();
	virtual void Process(Player &player);
	virtual void BrokenBolt(int id);
	void Draw(Player &player);
	virtual void DrawBullet(){}

protected:
	int mPositionX;
	int mPositionY;
	ss::Player *mSprite;

	bool mBoltExist[20];
	bool mHitExist[20];
	int numBolt;
	int numHit;
	int mState;

	int mGraphBolt;

	int mVoiceBroken;
	int mSoundBroken;
	int mSoundBlood;
	int mSoundBreath;
	int mSoundWind;
	int mBGM;
};