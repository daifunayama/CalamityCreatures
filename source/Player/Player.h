#pragma once
#include "../Input/Controller.h"
#include "../SSPlayer/SS5Player.h"
#include "../Enemy/Enemy.h"

/*
プレイヤーを制御するクラス
*/
class Player {
public:
	void Load();
	void Move(Enemy& enemy);
	void Draw();

private:
	Controller mController;
	int mGraph;

	int mPositionX;
	int mPositionY;
	int mAcceleX;
	int mAcceleY;
	bool mGround;
};