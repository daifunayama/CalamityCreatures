#pragma once
#include "../Enemy.h"
#include "../Bullet.h"

class E1 : public Enemy {
public:
	void Load();
	void LoadGraphic();
	void Process(Player &player);
	void BrokenBolt(int id);
	void DrawBullet();

private:
	int mShotCounter;
	Bullet mBullet;
};