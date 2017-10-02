#include "E0.h"
#include "../../Camera/Camera.h"
#include "../../Parameter.h"
#include "../../Utility.h"
#include "../../Effekseer/AnimationController.h"
#include "DxLib.h"

void E0::Load() {
	mPositionX = 400;
	mPositionY = -1300;

	mState = 0;

	mShotCounter = 0;

	for (int i = 0; i < 20; i++) {
		mBoltExist[i] = 0;
		mHitExist[i] = 0;
	}

	numBolt = 6;
	numHit = 7;
	numCore = 0;

	for (int i = 0; i < numBolt; i++)mBoltExist[i] = 1;
	for (int i = 0; i < numHit; i++)mHitExist[i] = 1;

	mGraphBolt = LoadGraph("Data/graphic/bolt.png");
	mGraphBolt2 = LoadGraph("Data/graphic/bolt2.png");

	mBullet.Load();
}

void E0::LoadGraphic() {
	//プレイヤーの作成
	mSprite = ss::Player::create();

	//プレイヤーにリソースを割り当て
	mSprite->setData("mill");// ssbpファイル名

	mSprite->play("mill/wait1");// アニメーション名を指定

	//スケール設定
	mSprite->setScale(2.0f, 2.0f);

	mSprite->setStep(0.6f);

	mSoundBlood = LoadSoundMem("Data/E1/蒸気.mp3");
	mSoundBroken = LoadSoundMem("Data/se/decision18.mp3");

	mBGM = LoadSoundMem("Data/bgm/bgm_maoudamashii_fantasy13.mp3");
}

void E0::Process(int &state, Player &player) {

	mSprite->setPosition(mPositionX - Camera::getInstance().getPositonX(),
		Parameter::WINDOW_HEIGHT - mPositionY + Camera::getInstance().getPositonY());

	//初期
	if (mState == 0) {
	
		if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "wait1") {
			mSprite->play("mill/wait1");
			mSprite->setStep(0.3f);
		}
		

		if (state == 1 && !CheckSoundMem(mBGM))PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP);

		if (!mBoltExist[0] && !mBoltExist[1] && !mBoltExist[2] && !mBoltExist[3]) {
			mState = 1;
			PlaySoundMem(mSoundBlood, DX_PLAYTYPE_BACK);
		}
	}

	if (mState == 1) {
		if (mSprite->getPlayAnimeName() != "wait2") {
			mSprite->play("mill/wait2");
			mSprite->setStep(0.6f);
		}

		if (!mBoltExist[0] && !mBoltExist[1] && !mBoltExist[2] && !mBoltExist[3] && !mBoltExist[4] && !mBoltExist[5]) {
			state = 2;
			StopSoundMem(mBGM);
			mSprite->setStep(0.3f);
		}
	}


	mSprite->update((float)30 / 1000);

	mBullet.Process();
}

void E0::BrokenBolt(int id) {
	mBoltExist[id-1] = 0;
	PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);
}

void E0::DrawBullet() {
	mBullet.Draw();
}

void E0::Draw(Player &player) {
	mSprite->draw();

	AnimationController::getInstance().DrawFire();

	ss::ResluteState state;
	string pass;
	for (int n = 0; n < numBolt; n++) {
		pass.clear();
		pass = "bolt" + Utility::IntToString(n + 1);

		mSprite->getPartState(state, pass.c_str());
		
		if (mBoltExist[n]) {
			if (player.getCatchId() > 100 && n == player.getCatchId() - 101 && player.getBoltBreakCounter() > 10) {
				DrawRotaGraph(state.x, Parameter::WINDOW_HEIGHT - state.y, 1,
					player.getBoltBreakCounter() * 2 - state.rotationZ * Parameter::PI / 180, mGraphBolt, 1, 0);
			}
			else DrawRotaGraph(state.x, Parameter::WINDOW_HEIGHT - state.y, 1, -state.rotationZ * Parameter::PI / 180, mGraphBolt, 1, 0);
		}

		else DrawRotaGraph(state.x, Parameter::WINDOW_HEIGHT - state.y, 1, -state.rotationZ * Parameter::PI / 180, mGraphBolt2, 1, 0);
	}
}