#include "E2.h"
#include "../../Camera/Camera.h"
#include "../../Parameter.h"
#include "../../Utility.h"
#include "../../Effekseer/AnimationController.h"
#include "DxLib.h"

void E2::Load() {
	mPositionX = -1000;
	mPositionY = -550;

	mState = 0;

	for (int i = 0; i < 20; i++) {
		mBoltExist[i] = 0;
		mHitExist[i] = 0;
	}

	numBolt = 3;
	numHit = 1;

	for (int i = 0; i < numBolt; i++)mBoltExist[i] = 1;
	for (int i = 0; i < numHit; i++)mHitExist[i] = 1;

	mGraphBolt = LoadGraph("Data/graphic/bolt.png");
}

void E2::LoadGraphic() {
	//プレイヤーの作成
	mSprite = ss::Player::create();

	//プレイヤーにリソースを割り当て
	mSprite->setData("armor");// ssbpファイル名

	mSprite->play("armor/wait1");// アニメーション名を指定

	//スケール設定
	mSprite->setScale(1.5f, 1.5f);

	mSprite->setStep(0.3f);

	//mSoundBreath = LoadSoundMem("Data/E2/歯車・回転中.mp3");

	mVoiceBroken = LoadSoundMem("Data/E1/ドラゴン・鳴き声02.mp3");
	mSoundBlood = LoadSoundMem("Data/E1/蒸気.mp3");
	mSoundBroken = LoadSoundMem("Data/E1/robot-footstep1.mp3");
	
	mSoundSword = LoadSoundMem("Data/E2/shock4.mp3");

	mBGM = LoadSoundMem("Data/E1/hsd.mp3");
}

void E2::Process(int &state, Player &player) {

	mSprite->setPosition(mPositionX - Camera::getInstance().getPositonX(),
		Parameter::WINDOW_HEIGHT - mPositionY + Camera::getInstance().getPositonY());

	//初期
	if (mState == 0) {
		if (player.getCatchId() == 1) {
			if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch1") {
				mSprite->play("armor/catch1");
				mSprite->setStep(0.4f);
			}
		}
		if (player.getCatchId() == 0) {
			if (CheckHitKey(KEY_INPUT_1) == 1) {
				if (mSprite->getPlayAnimeName() != "atack1") {
					mSprite->play("armor/atack1");
					mSprite->setStep(0.3f);
					mSprite->setFrameNo(1);
				}
			}
			if (mSprite->getPlayAnimeName() == "atack1" && mSprite->getFrameNo() == 37 && !CheckSoundMem(mSoundSword)) {
				Camera::getInstance().SetQuakeWindow(80, 20);
				PlaySoundMem(mSoundSword, DX_PLAYTYPE_BACK);
			}

			if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "wait1") {
				mSprite->play("armor/wait1");
				mSprite->setStep(0.3f);
			}
		}

		if (!CheckSoundMem(mSoundBreath))PlaySoundMem(mSoundBreath, DX_PLAYTYPE_LOOP);
		
	}

	//ボルト2破壊中
	if (mState == 1) {
		//アニメが1周したとき
		if (mSprite->getPlayAnimeName() == "break1" && mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {

			mSprite->play("armor/angry");
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
			mSprite->play("armor/wait1");
			mSprite->setStep(0.3f);
		}
		if (CheckSoundMem(mSoundBreath))StopSoundMem(mSoundBreath);
		if (!CheckSoundMem(mBGM))PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP);
	}

	mSprite->update((float)30 / 1000);
}

void E2::BrokenBolt(int id) {
	if (mState == 0) {
		if (id == 2) {
			mBoltExist[1] = 0;
			mHitExist[3] = 0;
			mHitExist[7] = 0;
			mState = 1;

			PlaySoundMem(mSoundBlood, DX_PLAYTYPE_BACK);
			PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);

			mSprite->play("armor/break1");
			mSprite->setStep(0.5f);
		}
	}
}

