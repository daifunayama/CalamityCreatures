#pragma once
#include <windows.h>
#include "Scene.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "../Parameter.h"

/*
í¬V[NX
í¬KvÈð·×ÄÇ·é
*/
class BattleScene : public Scene {
public:
	BattleScene() :Scene(Parameter::SCENE_BATTLE) {
		Load();
	}

	void Load();
	void Process();
	void Drawing();
	void DrawTask();
	void Remove();

private:
	int mState;
	int mCounter;
	Player mPlayer;						//í¬vC[
	Enemy* mEnemy;
	//HPGauge mHPGauge[2];					//HPQ[W
	//BackGround mBackGround;					//wi
	int mBack;
	int mGraphStart;
	int mGraphComplete;

	int mSoundStart;
	int mSoundFinish;
	int mSoundTask;
};