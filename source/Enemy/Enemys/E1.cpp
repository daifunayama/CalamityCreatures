#include "E1.h"
#include "../../Camera/Camera.h"
#include "../../Parameter.h"
#include "../../Utility.h"
#include "../../Effekseer/AnimationController.h"
#include "DxLib.h"

void E1::Load() {
	mPositionX = 400;
	mPositionY = -600;

	mState = 0;

	mShotCounter = 0;

	for (int i = 0; i < 20; i++) {
		mBoltExist[i] = 0;
		mHitExist[i] = 0;
	}

	numBolt = 3;
	numHit = 8;

	for (int i = 0; i < numBolt; i++)mBoltExist[i] = 1;
	for (int i = 0; i < numHit; i++)mHitExist[i] = 1;

	mGraphBolt = LoadGraph("Data/graphic/bolt.png");

	mBullet.Load();
}

void E1::LoadGraphic() {
	//プレイヤーの作成
	mSprite = ss::Player::create();

	//プレイヤーにリソースを割り当て
	mSprite->setData("spider");// ssbpファイル名

	mSprite->play("spider/wait1");// アニメーション名を指定

								  //スケール設定
	mSprite->setScale(2.5f, 2.5f);

	mSprite->setStep(0.3f);

	//mSoundBreath = LoadSoundMem("Data/E1/歯車・回転中.mp3");

	mVoiceBroken = LoadSoundMem("Data/E1/ドラゴン・鳴き声02.mp3");
	mSoundBlood = LoadSoundMem("Data/E1/蒸気.mp3");
	mSoundBroken = LoadSoundMem("Data/E1/robot-footstep1.mp3");
	mSoundWind = LoadSoundMem("Data/E1/天候・荒野の風.mp3");

	mBGM = LoadSoundMem("Data/E1/hsd.mp3");
}

void E1::Process(Player &player) {

	mSprite->setPosition(mPositionX - Camera::getInstance().getPositonX(),
		Parameter::WINDOW_HEIGHT - mPositionY + Camera::getInstance().getPositonY());

	//初期
	if (mState == 0) {
		if (player.getCatchId() == 2) {
			if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch1") {
				mSprite->play("spider/catch1");
				mSprite->setStep(0.5f);
			}
		}
		else if (player.getCatchId() == 1) {
			if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch2") {
				mSprite->play("spider/catch2");
				mSprite->setStep(0.5f);
			}
		}
		else {
			if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "wait1") {
				mSprite->play("spider/wait1");
				mSprite->setStep(0.3f);
			}
		}

		if (!CheckSoundMem(mSoundBreath))PlaySoundMem(mSoundBreath, DX_PLAYTYPE_LOOP);
		if (!CheckSoundMem(mSoundWind))PlaySoundMem(mSoundWind, DX_PLAYTYPE_LOOP);
	}

	//ボルト2破壊中
	if (mState == 1) {
		//アニメが1周したとき
		if (mSprite->getPlayAnimeName() == "break1" && mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {

			mSprite->play("spider/angry");
			mSprite->setStep(0.6f);
			mSprite->setPartVisible("joint1_1", false);
			mSprite->setPartVisible("joint1_4", false);
			mSprite->setPartVisible("joint1_5", false);
			mSprite->setPartVisible("foot1-2_1", false);
			mSprite->setPartVisible("foot1-1_1", false);
			mSprite->setPartVisible("foot2-2_1", false);
		}

		if (mSprite->getPlayAnimeName() == "angry") {
			if (mSprite->getFrameNo() == 10)PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1)mState = 2;
		}
	}

	//ボルト2破壊後
	if (mState == 2) {
		if (mSprite->getPlayAnimeName() != "wait1") {
			mSprite->play("spider/wait1");
			mSprite->setStep(0.3f);
		}
		if (CheckSoundMem(mSoundBreath))StopSoundMem(mSoundBreath);
		if (CheckSoundMem(mSoundWind))StopSoundMem(mSoundWind);
		if (!CheckSoundMem(mBGM))PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP);

		mShotCounter++;

		if (mShotCounter == 60 || mShotCounter == 70 || mShotCounter == 80) {
			mBullet.CreateShot(mPositionX, mPositionY + 250,
				atan2f(player.getPositionY() - mPositionY + 250, player.getPositionX() - mPositionX), 20, 10);
		}
		if (mShotCounter == 80)mShotCounter = 0;
	}

	mSprite->update((float)30 / 1000);

	mBullet.Process();
}

void E1::BrokenBolt(int id) {
	if (mState == 0) {
		if (id == 2) {
			mBoltExist[1] = 0;
			mHitExist[3] = 0;
			mHitExist[7] = 0;
			mState = 1;

			PlaySoundMem(mSoundBlood, DX_PLAYTYPE_BACK);
			PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);

			mSprite->play("spider/break1");
			mSprite->setStep(0.5f);
		}
	}
}

void E1::DrawBullet() {
	mBullet.Draw();
}