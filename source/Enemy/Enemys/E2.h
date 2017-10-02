#pragma once
#include "../Enemy.h"

class E2 : public Enemy {
public:
	void Load();
	void LoadGraphic();
	void Process(int &state, Player &player);
	void BrokenBolt(int id);


private:
	int mSoundSword;
};