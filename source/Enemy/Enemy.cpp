#include "Enemy.h"
#include "../Camera/Camera.h"
#include "../Parameter.h"
#include "../Utility.h"
#include "../Effekseer/AnimationController.h"
#include "DxLib.h"

Quad Enemy::getQuad(const char* name) {
	Quad mQuad = mSprite->getPartQuad(name);
	return mQuad;
}

void Enemy::Load() {

}

void Enemy::LoadGraphic() {

}

void Enemy::Process(Player &player) {

	mSprite->update((float)30 / 1000);
}

void Enemy::BrokenBolt(int id) {
	
}

void Enemy::Draw(Player &player) {
	mSprite->draw();

	AnimationController::getInstance().DrawFire();
	
	/*
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	
	Quad mQuad = mSprite->getPartQuad("bolt2");

	//SetDrawBlendMode(DX_BLENDMODE_ALPHA_X4, 100);
	//DrawModiGraphF(mQuad.tl().x(),mQuad.tl().y(), mQuad.tr().x(), mQuad.tr().y(), 
	//	mQuad.br().x(),  mQuad.br().y(), mQuad.bl().x(),  mQuad.bl().y(), box, true);

	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	
	for (int x = 0; x < 1280; x++) {
		for (int y = 0; y < 780; y++) {
			//if (mQuad > v)DrawPixel(x, y, Parameter::COLOR_RED);
			if(Utility::CheckQuadPointHit(mQuad,x,y))DrawPixel(x, y, Parameter::COLOR_RED);
		}
	}
	*/

	ss::ResluteState state;
	string pass;
	for (int n = 0; n < numBolt; n++) {
		if (mBoltExist[n]) {
			pass.clear();
			pass = "bolt" + Utility::IntToString(n + 1);

			mSprite->getPartState(state, pass.c_str());

			if (player.getCatchId() > 100 && n == player.getCatchId() - 101 && player.getBoltBreakCounter() > 10) {
				DrawRotaGraph(state.x, Parameter::WINDOW_HEIGHT - state.y, 1, 
					player.getBoltBreakCounter()*2-state.rotationZ * Parameter::PI / 180, mGraphBolt, 1, 0);
			}
			else DrawRotaGraph(state.x, Parameter::WINDOW_HEIGHT - state.y, 1, -state.rotationZ * Parameter::PI / 180, mGraphBolt, 1, 0);
		}
	}
}