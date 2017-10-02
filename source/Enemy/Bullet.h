#pragma once
#include "../HitBox/HitBox.h"

class Player;

class Bullet {
public:
	void Load();
	void CreateShot(int x, int y, float angle, int speed, int r);
	void Process();
	void CheckHit(Player &player);
	void Draw();

	struct Shot{
		int positionX;
		int positionY;
		float angle;
		int speed;
		bool exist;
		int r;
		HitBox mHitBox;
	};
	int mGraph;
	int mSE;
	Shot mShot[200];
};