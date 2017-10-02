#include "BattleScene.h"
#include "../Input/Input.h"
#include "../Effekseer/AnimationController.h"
#include "../Enemy/Enemys/E0.h"
#include "../Enemy/Enemys/E1.h"
#include "../Enemy/Enemys/E2.h"
#include "../Camera/Camera.h"
#include "../Application.h"

/*リソースのロードと初期化*/
void BattleScene::Load() {
	LoadGraphScreen(0, 0, "Data/graphic/logo.png", 0);
	ScreenFlip();

	mState = 0;
	mCounter = 0;

	if (Application::mChapterId == 1)mBack = LoadGraph("Data/graphic/bg1.png");
	if (Application::mChapterId == 2)mBack = LoadGraph("Data/graphic/bg2.png");


	mGraphStart = LoadGraph("Data/graphic/ui/missionstart.png");
	mGraphComplete = LoadGraph("Data/graphic/ui/missioncomplete.png");

	mSoundStart = LoadSoundMem("Data/se/sceneswitch2.mp3");
	mSoundFinish = LoadSoundMem("Data/se/decision16.mp3");
	mSoundTask = LoadSoundMem("Data/se/sen_ge_pis_kamaeru02.mp3");

	mPlayer.Load();

	if (Application::mChapterId == 2)mEnemy = new E1();
	else if (Application::mChapterId == 3)mEnemy = new E2();
	else mEnemy = new E0();

	mEnemy->Load();
	mEnemy->LoadGraphic();

	Camera::getInstance().Init();
}

/*更新*/
void BattleScene::Process() {

	if (mState == 0) {
		mCounter++;

		if (mCounter == 200) {
			mState = 1;
			mCounter = 0;
		}
	}

	if (mState == 2) {
		mCounter++;

		if (mCounter == 200) {
			Application::mChapterId++;
			Application::mNextSceneId = Parameter::SCENE_NOVEL;
		}
	}

	//カメラのアップデート
	Camera::getInstance().Update(mPlayer, *mEnemy);


	mPlayer.Move(mState, *mEnemy);
	mEnemy->Process(mState, mPlayer);
	mEnemy->CheckBulletHit(mPlayer);

	AnimationController::getInstance().Process();
}

/*描画*/
void BattleScene::Drawing() {
	if (Application::mChapterId == 2)SetDrawBright(120, 120, 120);
	
	if (Application::mChapterId == 1)DrawGraph(-1800-Camera::getInstance().getPositonX(), -4800-Camera::getInstance().getPositonY(), mBack, true);
	if (Application::mChapterId == 2)DrawGraph(-1800 - Camera::getInstance().getPositonX(), -4500 - Camera::getInstance().getPositonY(), mBack, true);

	mEnemy->Draw(mPlayer);

	if (Application::mChapterId == 2)SetDrawBright(255, 255, 255);
	AnimationController::getInstance().DrawLayer2();
	if (Application::mChapterId == 2)SetDrawBright(120, 120, 120);


	mPlayer.Draw();

	if (Application::mChapterId == 2)SetDrawBright(255, 255, 255);

	mEnemy->DrawBullet();

	if (mState == 0) {//155
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawBox(0, 0, Parameter::WINDOW_WIDTH, Parameter::WINDOW_HEIGHT, Parameter::COLOR_BLACK, 1);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		if (mCounter < 50)DrawGraph(155 + mCounter * 50 - 2500, 200, mGraphStart, 1);
		else if(mCounter < 150)DrawGraph(155, 200, mGraphStart, 1);
		else DrawGraph(155 + (mCounter - 150) * 50, 200, mGraphStart, 1);

		DrawTask();

		if (mCounter == 50)PlaySoundMem(mSoundStart, DX_PLAYTYPE_BACK);
	}

	if (mState == 2) {//155
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 120);
		DrawBox(0, 0, Parameter::WINDOW_WIDTH, Parameter::WINDOW_HEIGHT, Parameter::COLOR_BLACK, 1);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

		if (mCounter < 50)DrawGraph(155 + mCounter * 50 - 2500, 300, mGraphComplete, 1);
		else if (mCounter < 150)DrawGraph(155, 300, mGraphComplete, 1);
		else DrawGraph(155 + (mCounter - 150) * 50, 300, mGraphComplete, 1);

		if (mCounter == 1)PlaySoundMem(mSoundFinish, DX_PLAYTYPE_BACK);
	}

	//DrawFormatString(10, 10, Parameter::COLOR_RED, "%d %d", Camera::getInstance().getPositonX(), Camera::getInstance().getPositonY());
}

void BattleScene::DrawTask() {
	if (mCounter >= 70 && mCounter < 150) {
		if (Application::mChapterId == 1) {
			DrawStringToHandle(220, 400, "・大風車のボルトをすべて締め直せ", Parameter::COLOR_WHITE, Parameter::FONT_40);
			if (mCounter == 70)PlaySoundMem(mSoundTask, DX_PLAYTYPE_BACK);
		}

		if (Application::mChapterId == 2) {
			DrawStringToHandle(220, 400, "・カラクリの弱点を探り解体せよ", Parameter::COLOR_WHITE, Parameter::FONT_40);
			if (mCounter == 70)PlaySoundMem(mSoundTask, DX_PLAYTYPE_BACK);
		}
	}

}

void BattleScene::Remove() {

}