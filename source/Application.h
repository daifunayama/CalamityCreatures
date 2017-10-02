#pragma once
#include "Scene/Scene.h"
#include "Scene\TitleScene.h"
#include "Scene/NovelScene.h"
#include "Scene/BattleScene.h"
#include "SSPlayer/SS5Player.h"
#include "Parameter.h"
#include "DxLib.h"

/*
ゲームを管理するクラス
シーンの転換と前のシーンの削除を行う
*/
class Application {
public:
	Application() {
		Parameter::InitFont();
		resman = ss::ResourceManager::getInstance();
		AddSpriteResource();
	/*	
		mChapterId = 2;
	
		WaitKey();
		if (CheckHitKey(KEY_INPUT_N)) {
			mScene = new NovelScene();
			mOldSceneId = Parameter::SCENE_NOVEL;
		}
		else {
			mScene = new BattleScene();
			mOldSceneId = Parameter::SCENE_BATTLE;
		}
		*/
		mScene = new TitleScene();
		mOldSceneId = Parameter::SCENE_TITLE;

		mNextSceneId = mOldSceneId;
	}
	~Application(){}

	void MainLoop();

	void AddSpriteResource();
	

public:
	static int mOldSceneId;				//前のシーンID
	static int mNextSceneId;			//新しいシーンID
	static ss::ResourceManager *resman; //スプライトのリソースマネージャー

	static int mChapterId;

private:
	Scene* mScene;						//シーン
};