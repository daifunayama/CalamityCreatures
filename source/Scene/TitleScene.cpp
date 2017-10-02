#include "TitleScene.h"
#include "../Application.h"

void TitleScene::Init() {

}

void TitleScene::Load() {
	mGraphTitle = LoadGraph("Data/graphic/title.png");
	mSoundEnter = LoadSoundMem("Data/se/decision16.mp3");
}

void TitleScene::Process() {
	mController.ConvertInput();

	if (mController.getKey(3) == 1) {
		Application::mNextSceneId = Parameter::SCENE_NOVEL;
		Application::mChapterId = 1;

		PlaySoundMem(mSoundEnter, DX_PLAYTYPE_BACK);
		Remove();
	}
}

void TitleScene::Drawing() {
	DrawGraph(0, 0, mGraphTitle, 0);
}
void TitleScene::Remove() {

}