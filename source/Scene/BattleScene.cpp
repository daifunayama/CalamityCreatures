#include "BattleScene.h"
#include "../Input/Input.h"
#include "../Effekseer/AnimationController.h"
#include "../Enemy/Enemys/E0.h"
#include "../Enemy/Enemys/E1.h"
#include "../Enemy/Enemys/E2.h"
#include "../Camera/Camera.h"

/*���\�[�X�̃��[�h�Ə�����*/
void BattleScene::Load() {
	mBack = LoadGraph("Data/graphic/background2.png");

	mPlayer.Load();

	if (CheckHitKey(KEY_INPUT_1))mEnemy = new E1();
	if (CheckHitKey(KEY_INPUT_2))mEnemy = new E2();
	else mEnemy = new E0();
	mEnemy->Load();
	mEnemy->LoadGraphic();
}

/*�X�V*/
void BattleScene::Process() {

	mEnemy->Process(mPlayer);
	mPlayer.Move(*mEnemy);
	
	//�J�����̃A�b�v�f�[�g
	Camera::getInstance().Update(mPlayer, *mEnemy);

	AnimationController::getInstance().Process();
}

/*�`��*/
void BattleScene::Drawing() {
	SetDrawBright(180, 180, 180);
	DrawGraph(-1800-Camera::getInstance().getPositonX(), -2000-Camera::getInstance().getPositonY(), mBack, true);
	SetDrawBright(255, 255, 255);



	mEnemy->Draw(mPlayer);

	AnimationController::getInstance().DrawLayer2();

	mPlayer.Draw();

	mEnemy->DrawBullet();
}
