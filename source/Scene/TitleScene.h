#pragma once
#include "Scene.h"
#include "../Input/Controller.h"
#include "../Parameter.h"

class TitleScene : public Scene {
public:
	TitleScene() : Scene(Parameter::SCENE_TITLE) {
		Load();
	}
	void Init();
	void Load();
	void Process();
	void Drawing();
	void Remove();

private:
	Controller mController;

	int mGraphTitle;

	int mSoundEnter;
};