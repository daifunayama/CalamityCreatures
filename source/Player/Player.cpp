#include "Player.h"
#include "../Enemy/Enemys/E1.h"
#include "../Parameter.h"
#include "../Utility.h"
#include "../SSPlayer/SS5Player.h"
#include "DxLib.h"

void Player::Load() {
	//mGraph = LoadGraph("Data/")
	mPositionX = 100;
	mPositionY = 100;
}

void Player::Move(Enemy &enemy) {
	mController.ConvertInput();

	if (mController.getUp())mPositionY -= 3;
	if (mController.getDown())mPositionY += 3;
	if (mController.getRight())mPositionX += 3;
	if (mController.getLeft())mPositionX -= 3;

	Quad mQuad = enemy.getQuad("armB2");

	Vertex v((float)mPositionX, (float)mPositionY);
	
	if (mQuad > v)DrawString(10, 10, "HIT", Parameter::COLOR_WHITE, 0);
}

void Player::Draw() {
	DrawCircle(mPositionX, mPositionY, 5, Parameter::COLOR_BLUE, 1, 1);

	
}