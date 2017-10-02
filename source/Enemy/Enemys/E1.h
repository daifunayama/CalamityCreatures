#pragma once
#include "../Enemy.h"

class E1 : public Enemy {
public:
	void Load();
	void LoadGraphic();
	void Process(int &state, Player &player);
	void BrokenBolt(int id);
	void BrokenCore(int id);
	void DrawBullet();

private:
	int mSoundWind;
	int mSoundAtack1;
	int mSoundGround;
};