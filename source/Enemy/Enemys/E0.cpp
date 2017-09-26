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

	numBolt = 0;
	numHit = 7;

	for (int i = 0; i < numBolt; i++)mBoltExist[i] = 1;
	for (int i = 0; i < numHit; i++)mHitExist[i] = 1;

	mGraphBolt = LoadGraph("Data/graphic/bolt.png");

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

	//mSoundBreath = LoadSoundMem("Data/E0/歯車・回転中.mp3");

	mVoiceBroken = LoadSoundMem("Data/E0/ドラゴン・鳴き声02.mp3");
	mSoundBlood = LoadSoundMem("Data/E0/蒸気.mp3");
	mSoundBroken = LoadSoundMem("Data/E0/robot-footstep1.mp3");
	mSoundWind = LoadSoundMem("Data/E0/天候・荒野の風.mp3");

	mBGM = LoadSoundMem("Data/E0/hsd.mp3");
}

void E0::Process(Player &player) {

	mSprite->setPosition(mPositionX - Camera::getInstance().getPositonX(),
		Parameter::WINDOW_HEIGHT - mPositionY + Camera::getInstance().getPositonY());

	//初期
	if (mState == 0) {
	
		if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "wait1") {
			mSprite->play("mill/wait1");
			mSprite->setStep(0.3f);
		}
		

		if (!CheckSoundMem(mSoundBreath))PlaySoundMem(mSoundBreath, DX_PLAYTYPE_LOOP);
		if (!CheckSoundMem(mSoundWind))PlaySoundMem(mSoundWind, DX_PLAYTYPE_LOOP);
	}


	mSprite->update((float)30 / 1000);

	mBullet.Process();
}

void E0::BrokenBolt(int id) {
	if (mState == 0) {
		if (id == 2) {
			mBoltExist[1] = 0;
			mHitExist[3] = 0;
			mHitExist[7] = 0;
			mState = 1;

			PlaySoundMem(mSoundBlood, DX_PLAYTYPE_BACK);
			PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);

			mSprite->play("mill/break1");
			mSprite->setStep(0.5f);
		}
	}
}

void E0::DrawBullet() {
	mBullet.Draw();
}