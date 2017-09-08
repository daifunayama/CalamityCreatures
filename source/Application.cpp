#include "Application.h"
#include "Input/Input.h"
#include "SSPlayer\SS5Player.h"
#include "Effekseer\AnimationController.h"
#include "DxLib.h"

int Application::mOldSceneId = Parameter::SCENE_TITLE;
int Application::mNextSceneId = Parameter::SCENE_TITLE;

ss::ResourceManager* Application::resman = nullptr;

/*�Q�[���̃��C�����[�v�̏���*/
void Application::MainLoop() {
	Input::getInstance().Update();

	//�V�[��ID���قȂ�ꍇ�̓V�[���؂�ւ�
	if (mNextSceneId != mOldSceneId) {

		delete mScene;
		AnimationController::getInstance().Reset();

		switch (mNextSceneId) {

		case Parameter::SCENE_BATTLE :
			mScene = new BattleScene();
			break;
		}

		mOldSceneId = mNextSceneId;
		
	}
	
	mScene->Process();
	mScene->Drawing();
}

/*�L�����X�v���C�g�̃��\�[�X�ǉ�*/
void  Application::AddSpriteResource() {
	Application::resman->addData("Data/E1/spider.ssbp");
	Application::resman->addData("Data/heroine/heroine.ssbp");
}