#include "BattleScene.h"
#include "../Input/Input.h"
#include "../Effekseer/AnimationController.h"
#include "../Enemy/Enemys/E1.h"

/*リソースのロードと初期化*/
void BattleScene::Load() {
	mPlayer.Load();

	mEnemy = new E1();
	mEnemy->LoadGraphic();
}

/*更新*/
void BattleScene::Process() {
	mPlayer.Move(*mEnemy);
	mEnemy->Process();
}

/*描画*/
void BattleScene::Drawing() {
	mEnemy->Draw();
	mPlayer.Draw();
}
