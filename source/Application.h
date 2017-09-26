#pragma once
#include "Scene\Scene.h"
#include "Scene\NovelScene.h"
#include "Scene/BattleScene.h"
#include "SSPlayer/SS5Player.h"
#include "Parameter.h"
#include "DxLib.h"

/*
�Q�[�����Ǘ�����N���X
�V�[���̓]���ƑO�̃V�[���̍폜���s��
*/
class Application {
public:
	Application() {
		Parameter::InitFont();
		resman = ss::ResourceManager::getInstance();
		AddSpriteResource();
	
		WaitKey();
		if (CheckHitKey(KEY_INPUT_N)) {
			mScene = new NovelScene();
			mOldSceneId = Parameter::SCENE_NOVEL;
		}
		else {
			mScene = new BattleScene();
			mOldSceneId = Parameter::SCENE_BATTLE;
		}
		mNextSceneId = mOldSceneId;
	}
	~Application(){}

	void MainLoop();

	void AddSpriteResource();
	

public:
	static int mOldSceneId;				//�O�̃V�[��ID
	static int mNextSceneId;			//�V�����V�[��ID
	static ss::ResourceManager *resman; //�X�v���C�g�̃��\�[�X�}�l�[�W���[

private:
	Scene* mScene;						//�V�[��
};