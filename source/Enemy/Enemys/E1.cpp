#include "E1.h"
#include "../../Camera/Camera.h"
#include "../../Parameter.h"
#include "../../Utility.h"
#include "../../Effekseer/AnimationController.h"
#include "DxLib.h"

void E1::Load() {
	mPositionX = 1400;
	mPositionY = -600;

	mState = 0;

	mShotCounter = 0;

	for (int i = 0; i < 20; i++) {
		mBoltExist[i] = 0;
		mHitExist[i] = 0;
		mCoreExist[i] = 0;
	}

	numBolt = 2;
	numHit = 8;
	numCore = 1;

	for (int i = 0; i < numBolt; i++)mBoltExist[i] = 1;
	for (int i = 0; i < numHit; i++)mHitExist[i] = 1;
	for (int i = 0; i < numCore; i++)mCoreExist[i] = 1;

	mGraphBolt = LoadGraph("Data/graphic/bolt.png");
	mGraphCore = LoadGraph("Data/graphic/bolt3.png");

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
	mSoundAtack1 = LoadSoundMem("Data/se/katana-gesture1.mp3");
	mSoundGround = LoadSoundMem("Data/se/爆破・水上爆発01.mp3");

	mBGM = LoadSoundMem("Data/E1/hsd.mp3");
}

void E1::Process(int &state, Player &player) {

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

	//ボルト2破壊
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
			mSprite->setPartVisible("eye_3", false);
			mSprite->setPartVisible("eye_4", false);
		}

		if (mSprite->getPlayAnimeName() == "angry") {
			if (mSprite->getFrameNo() == 10)PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1)mState = 2;

			if (player.getCatchId() > 0)player.Damaged();
		}
	}

	//ボルト2破壊後
	if (mState == 2) {

		if (!mBoltExist[0] && !mBoltExist[1])mState = 5;

		else {
			if (player.getCatchId() == 1) {
				if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch3") {
					mSprite->play("spider/catch3");
					mSprite->setPartVisible("foot2-1", true);
					mSprite->setPartVisible("foot1-1_2", true);
					mSprite->setStep(0.5f);
				}
			}
			else if (player.getCatchId() == 2) {
				if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch1") {
					mSprite->play("spider/catch1");
					mSprite->setStep(0.5f);
				}
			}
			else if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "wait1") {
				mSprite->play("spider/wait1");
				mSprite->setStep(0.3f);
			}

			//ひっかき攻撃
			if (mSprite->getPlayAnimeName() == "catch3") {
				if (mSprite->getFrameNo() >= 75 && mSprite->getFrameNo() <= 80) {
					ss::ResluteState pState;
					Quad quad = getQuad("foot2-1");
					player.getSprite()->getPartState(pState, "root");

					if (player.getCatchId() > 0 && Utility::CheckQuadPointHit(quad, pState.x, Parameter::WINDOW_HEIGHT - pState.y)) {
						player.Damaged();
					}
				}

				if (mSprite->getFrameNo() == 75) {
					PlaySoundMem(mSoundAtack1, DX_PLAYTYPE_BACK);
				}
			}


			if (CheckSoundMem(mSoundBreath))StopSoundMem(mSoundBreath);
			if (CheckSoundMem(mSoundWind))StopSoundMem(mSoundWind);
			if (!CheckSoundMem(mBGM))PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP);

			mShotCounter++;

			if (player.getCatchId() != 1 && player.getPositionY() > 100) {
				if (mShotCounter == 60 || mShotCounter == 70 || mShotCounter == 80) {
					mBullet.CreateShot(mPositionX, mPositionY + 250,
						atan2f(player.getPositionY() - mPositionY - 250, player.getPositionX() - mPositionX), 20, 10);
				}
			}
			if (mShotCounter == 100)mShotCounter = 0;
		}
	}

	//ボルト1破壊
	if (mState == 3) {
		//アニメが1周したとき
		if (mSprite->getPlayAnimeName() == "break2" && mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {

			mSprite->play("spider/angry");
			mSprite->setStep(0.6f);
			mSprite->setPartVisible("joint1", false);
			mSprite->setPartVisible("joint1_2", false);
			mSprite->setPartVisible("joint1_3", false);
			mSprite->setPartVisible("foot1-2", false);
			mSprite->setPartVisible("foot1-1", false);
			mSprite->setPartVisible("foot2-2", false);
			mSprite->setPartVisible("eye_1", false);
			mSprite->setPartVisible("eye_2", false);
		}

		if (mSprite->getPlayAnimeName() == "angry") {
			if (mSprite->getFrameNo() == 10)PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1)mState = 4;

			if (player.getCatchId() > 0)player.Damaged();
		}
	}

	//ボルト1破壊後
	if (mState == 4) {

		if (!mBoltExist[0] && !mBoltExist[1])mState = 5;
		
		else {
			if (player.getCatchId() == 2) {
				if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch1") {
					mSprite->play("spider/catch1");
					mSprite->setStep(0.5f);
				}
			}
			else if (player.getCatchId() == 1) {
				if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "catch3") {
					mSprite->play("spider/catch3");
					mSprite->setPartVisible("foot2-1", true);
					mSprite->setPartVisible("foot1-1_2", true);
					mSprite->setStep(0.5f);
				}
			}
			else if (mSprite->getFrameNo() == 0 && mSprite->getPlayAnimeName() != "wait1") {
				mSprite->play("spider/wait1");
				mSprite->setStep(0.3f);
			}

			//ひっかき攻撃
			if (mSprite->getPlayAnimeName() == "catch3") {
				if (mSprite->getFrameNo() >= 75 && mSprite->getFrameNo() <= 80) {
					ss::ResluteState pState;
					Quad quad = getQuad("foot2-1");
					player.getSprite()->getPartState(pState, "root");

					if (player.getCatchId() > 0 && Utility::CheckQuadPointHit(quad, pState.x, Parameter::WINDOW_HEIGHT - pState.y)) {
						player.Damaged();
					}
				}

				if (mSprite->getFrameNo() == 75) {
					PlaySoundMem(mSoundAtack1, DX_PLAYTYPE_BACK);
				}
			}

			if (CheckSoundMem(mSoundBreath))StopSoundMem(mSoundBreath);
			if (CheckSoundMem(mSoundWind))StopSoundMem(mSoundWind);
			if (!CheckSoundMem(mBGM))PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP);

			mShotCounter++;

			if (player.getCatchId() != 2 && player.getPositionY() > 100) {
				if (mShotCounter == 60 || mShotCounter == 70 || mShotCounter == 80) {
					mBullet.CreateShot(mPositionX, mPositionY + 250,
						atan2f(player.getPositionY() - mPositionY - 250, player.getPositionX() - mPositionX), 20, 10);
				}
			}
			if (mShotCounter == 100)mShotCounter = 0;
		}
	}

	//ボルト全破壊
	if (mState == 5) {
		if (mSprite->getPlayAnimeName() != "angry2") {
			mSprite->setPartVisible("joint1", false);
			mSprite->setPartVisible("foot1-1_2", true);
			mSprite->setPartVisible("joint1_6", true);
			mSprite->play("spider/angry2");
			mSprite->setStep(0.5f);
		}
		if (mSprite->getPlayAnimeName() == "angry2") {
			if (mSprite->getFrameNo() == 12 )PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
			if (mSprite->getFrameNo() == 70 && !CheckSoundMem(mSoundGround))PlaySoundMem(mSoundGround, DX_PLAYTYPE_BACK);
			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {
				mState = 6;
				mSprite->play("spider/wait2");
				mSprite->setStep(0.4f);
			}
			if (mSprite->getFrameNo() == 70)Camera::getInstance().SetQuakeWindow(100, 50);
		}
	}

	if (mState == 6) {
		mSprite->setPartVisible("foot1-2", true);
		mSprite->setPartVisible("foot1-2_7", true);
		mSprite->setPartVisible("foot1-2_8", true);
		mSprite->setPartVisible("foot1-2_9", true);
		mSprite->setPartVisible("joint1_16", true);
		mSprite->setPartVisible("joint1_18", true);
		mSprite->setPartVisible("foot2-1",true);
		mSprite->setPartVisible("joint1_14", true);
		mSprite->setPartVisible("joint1_11", true);
		mSprite->setPartVisible("eye_7", true);
		mSprite->setPartVisible("eye_8", true);

		if (mSprite->getPlayAnimeName() == "wait2") {
			mShotCounter++;

			if ((mShotCounter == 60 || mShotCounter == 70 || mShotCounter == 80) && player.getCatchId() < 200) {
				mBullet.CreateShot(mPositionX, mPositionY + 600,
					atan2f(player.getPositionY() - mPositionY - 600, player.getPositionX() - mPositionX), 20, 10);
			}

			if (mShotCounter >= 80) mShotCounter = 0;
			
		}
	
		if (mSprite->getPlayAnimeName() == "wait2" && mSprite->getFrameNo() == 0 && GetRand(4) == 0) {
			if (player.getCatchId() < 200) {
				mSprite->play("spider/jump");
				mSprite->setStep(0.5f);
			}
		}

		if (mSprite->getPlayAnimeName() == "jump") {
			if (player.getCatchId() > 0)player.Damaged();
			if (mSprite->getFrameNo() == 20)mPositionX = player.getPositionX();
			if (mSprite->getFrameNo() == 35) {
				if(!CheckSoundMem(mSoundGround))PlaySoundMem(mSoundGround, DX_PLAYTYPE_BACK);
				Camera::getInstance().SetQuakeWindow(100, 50);
			}
			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {
				mSprite->play("spider/atack1");
				mSprite->setStep(0.5f);
				mShotCounter = 0;
			}
		}

		if (mSprite->getPlayAnimeName() == "atack1") {
			mShotCounter++;

			if (mShotCounter % 10 == 1 && mShotCounter > 40 && mShotCounter < 180) {
				mBullet.CreateShot(mPositionX, mPositionY + 600,mShotCounter * Parameter::PI/180.0f, 20, 10);
			}

			//攻撃判定
			if (mSprite->getFrameNo() >= 90 && mSprite->getFrameNo() <= 98) {
				ss::ResluteState pState;
				Quad quad = getQuad("foot2-1_3");
				player.getSprite()->getPartState(pState, "root");

				if (Utility::CheckQuadPointHit(quad, pState.x, Parameter::WINDOW_HEIGHT - pState.y)) {
					player.Damaged();
				}
			
			}

			if (mSprite->getFrameNo() == 98) {
				PlaySoundMem(mSoundAtack1, DX_PLAYTYPE_BACK);
				Camera::getInstance().SetQuakeWindow(50, 20);
			}

			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {
				if (player.getCatchId() == 5) {
					mSprite->play("spider/catch4");
					mSprite->setStep(0.4f);
				}
				else {
					mSprite->play("spider/wait2");
					mSprite->setStep(0.5f);
				}

				mShotCounter = 0;
			}
		}

		if (mSprite->getPlayAnimeName() == "catch4") {

			//攻撃判定
			if (mSprite->getFrameNo() >= 55 && mSprite->getFrameNo() <= 64) {
				ss::ResluteState pState;
				Quad quad = getQuad("atack1");
				player.getSprite()->getPartState(pState, "root");

				if (player.getCatchId() > 0 && Utility::CheckQuadPointHit(quad, pState.x, Parameter::WINDOW_HEIGHT - pState.y)) {
					player.Damaged();
				}

			}

			if (mSprite->getFrameNo() == 24)PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);

			if (mSprite->getFrameNo() == 52)PlaySoundMem(mSoundAtack1, DX_PLAYTYPE_BACK);
			
			if (mSprite->getFrameNo() == mSprite->getMaxFrame() - 1) {
				mSprite->play("spider/wait2");
				mSprite->setStep(0.5f);
			}
		}
	}

	if (!mCoreExist[0]) {
		state = 2;
		StopSoundMem(mBGM);
		mSprite->setStep(0.3f);

		if (mSprite->getPlayAnimeName() != "wait3")mSprite->play("spider/wait3");
	}

	mSprite->update((float)30 / 1000);

	mBullet.Process();
}

void E1::BrokenBolt(int id) {
	if (id == 1) {
		mBoltExist[0] = 0;
		mHitExist[2] = 0;
		mHitExist[6] = 0;
		mState = 3;

		PlaySoundMem(mSoundBlood, DX_PLAYTYPE_BACK);
		PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
		PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);

		mSprite->play("spider/break2");
		mSprite->setStep(0.5f);

	}

	if (id == 2) {
		mBoltExist[1] = 0;
		mHitExist[3] = 0;
		mHitExist[7] = 0;
		mState = 1;

		PlaySoundMem(mSoundBlood, DX_PLAYTYPE_BACK);
		PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
		PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);

		mSprite->play("spider/break1");
		if (!mBoltExist[0])mSprite->setPartVisible("joint1", false);
		mSprite->setStep(0.5f);
	}

}

void E1::BrokenCore(int id) {
	if (id == 1) {
		mCoreExist[0] = 0;
		PlaySoundMem(mVoiceBroken, DX_PLAYTYPE_BACK);
		PlaySoundMem(mSoundBroken, DX_PLAYTYPE_BACK);

		mState = 7;
	}
}

void E1::DrawBullet() {
	mBullet.Draw();
}