#include "BattleScene.h"
#include "../Input/Input.h"
#include "../Effekseer/AnimationController.h"
#include "../Enemy/Enemys/E1.h"

/*���\�[�X�̃��[�h�Ə�����*/
void BattleScene::Load() {
	mPlayer.Load();

	mEnemy = new E1();
	mEnemy->LoadGraphic();
}

/*�X�V*/
void BattleScene::Process() {
	mPlayer.Move(*mEnemy);
	mEnemy->Process();
}

/*�`��*/
void BattleScene::Drawing() {
	mEnemy->Draw();
	mPlayer.Draw();
}
