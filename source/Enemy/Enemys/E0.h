#pragma once
#include "../Enemy.h"
#include "../Bullet.h"

class E0 : public Enemy {
public:
	void Load();
	void LoadGraphic();
	void Process(int &state, Player &player);
	void BrokenBolt(int id);
	void DrawBullet();
	void Draw(Player &player);

private:
	int mShotCounter;
	Bullet mBullet;
	int mGraphBolt2;
};