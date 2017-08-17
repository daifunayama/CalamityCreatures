#pragma once
#include "../Input/Controller.h"
#include "../SSPlayer/SS5Player.h"
#include "../Enemy/Enemy.h"

/*
�v���C���[�𐧌䂷��N���X
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