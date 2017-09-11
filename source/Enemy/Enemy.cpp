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
	mPositionX = 400;
	mPositionY = -600;

	mState = 0;

	for (int i = 0; i < 20; i++) {
		mBoltExist[i] = 0;
		mHitExist[i] = 0;
	}

	numBolt = 3;
	numHit = 8;

	for (int i = 0; i < numBolt; i++)mBoltExist[i] = 1;
	for (int i = 0; i < numHit; i++)mHitExist[i] = 1;

	mGraphBolt = LoadGraph("Data/graphic/bolt.png");
}

void Enemy::LoadGraphic() {
	//プレイヤーの作成
	mSprite = ss::Player::create();

	//プレイヤーにリソースを割り当て
	mSprite->setData("spider");// ssbpファイル名

	mSprite->play("spider/wait1");// アニメーション名を指定

	//スケール設定
	mSprite->setScale(2.5f,2.5f);

	mSprite->setStep(0.3f);

	//mSoundBreath = LoadSoundMem("Data/E1/歯車・回転中.mp3");

	mVoiceBroken = LoadSoundMem("Data/E1/ドラゴン・鳴き声02.mp3");
	mSoundBlood = LoadSoundMem("Data/E1/蒸気.mp3");
	mSoundBroken = LoadSoundMem("Data/E1/robot-footstep1.mp3");
	mSoundWind = LoadSoundMem("Data/E1/天候・荒野の風.mp3");

	mBGM = LoadSoundMem("Data/E1/hsd.mp3");
}

void Enemy::Process(Player &player) {

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
		if (mSprite->getPlayAnimeName() == "break1" && mSprite->getFrameNo() == mSprite->getMaxFrame()-1) {
			
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
		if (!CheckSoundMem(mBGM))PlaySoundMem(mBGM,DX_PLAYTYPE_LOOP);
	}
	
	mSprite->update((float)30 / 1000);
}

void Enemy::BrokenBolt(int id) {
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

void Enemy::Draw(Player &player) {
	mSprite->draw();

	AnimationController::getInstance().DrawFire();
	
	/*
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	
	Quad mQuad = mSprite->getPartQuad("hit6");

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