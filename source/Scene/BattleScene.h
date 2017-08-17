#pragma once
#include <windows.h>
#include "Scene.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "../Parameter.h"

/*
�퓬�V�[���N���X
�퓬���K�v�ȏ��������ׂĊǗ�����
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
	Player mPlayer;						//�퓬�v���C���[
	Enemy* mEnemy;
	//HPGauge mHPGauge[2];					//HP�Q�[�W
	//BackGround mBackGround;					//�w�i

	int mBGM;								//BGM�̃T�E���h�n���h��
};