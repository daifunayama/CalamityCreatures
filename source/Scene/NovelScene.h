#pragma once
#include "Scene.h"
#include "../Input/Controller.h"
#include "../Parameter.h"
#include <vector>
#include <string>

class NovelScene : public Scene{
public:
	NovelScene() : Scene(Parameter::SCENE_NOVEL) {
		Load();
	}
	void Init();
	void Load();
	void Process();
	void Drawing();
	void Remove();

private:
	void LoadFile();
	void Read();
	void ReadFromBuffer();
	void ReadCommand(std::string command);
	void DoCommand();

private:
	struct Character {
		int charaId;
		int faceId;
		int iconId;
	};

	struct CharaSprite {
		int base;
		int face[10];
		int icon[10];
	};

	Controller mController;
	bool mReadBufferEnable;
	bool mReadAfterCommand;
	int mNameId;
	int mBGId;
	int mAddCount;
	int mBufferLine;
	int mPoint[3];
	int mCurrentLine;

	int mBlackoutLevel;
	int mAllBlackoutLevel;
	int mWaitcounter;

	bool flagAllowEnter;
	bool flagAllowCommand;
	bool flagBlackout;
	bool flagAllBlackout;

	std::string name[10];
	std::string line[3];
	std::vector <std::string> Buffer;

	Character mChara[3];
	CharaSprite charaSprite[5];

	int mCG;

	int mChapterGraph;

	int mBackGround[5];
	int mWindow;
	int mCharaGraph[10];

	int mSoundMessage;
	int mSE[20];
	int mBGM;
};