#pragma once
#include <windows.h>
#include "Scene.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "../Parameter.h"

/*
戦闘シーンクラス
戦闘時必要な処理をすべて管理する
*/
class BattleScene : public Scene {
public:
	BattleScene() :Scene(Parameter::SCENE_BATTLE) {
		Load();
	}

	void Load();
	virtual void Process();
	virtual void Drawing();

private:
	Player mPlayer;						//戦闘プレイヤー
	Enemy* mEnemy;
	//HPGauge mHPGauge[2];					//HPゲージ
	//BackGround mBackGround;					//背景

	int mBGM;								//BGMのサウンドハンドル
};