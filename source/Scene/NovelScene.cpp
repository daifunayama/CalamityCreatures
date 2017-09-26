#include "NovelScene.h"
#include "DxLib.h"
#include "../Utility.h"
#include <fstream>

void NovelScene::Init() {
	name[0] = " ";
	name[1] = "�H�H�H";
	name[2] = "�`�[��";
	name[3] = "�M�����b�g";
	name[4] = "�A�����B��";

	mNameId = 0;
	mBGId = 0;
	mBufferLine = 0;
	mCurrentLine = 0;

	for (int i = 0; i < 3; i++) {
		mChara[i].charaId = 0;
		mChara[i].faceId = 1;
		mChara[i].iconId = 0;
	}

	mBlackoutLevel = 0;
	mAllBlackoutLevel = 255;
	mWaitcounter = 0;

	flagAllowEnter =false;
	flagAllowCommand = true;
	flagBlackout = false;
	flagAllBlackout = false;
}

void NovelScene::Load() {
	Init();
	LoadFile();

	mBackGround[0] = LoadGraph("Data/graphic/background/background1.png");
	mBackGround[1] = LoadGraph("Data/graphic/background/4-5-08-e.png");
	mBackGround[2] = LoadGraph("Data/graphic/background/background3.png");
	mWindow = LoadGraph("Data/graphic/ui/window.png");

	charaSprite[1].base = LoadGraph("Data/graphic/chara/chara1/base.png");
	charaSprite[1].face[1] = LoadGraph("Data/graphic/chara/chara1/face1.png");
	charaSprite[1].face[2] = LoadGraph("Data/graphic/chara/chara1/face2.png");
	charaSprite[1].face[3] = LoadGraph("Data/graphic/chara/chara1/face3.png");
	charaSprite[1].face[4] = LoadGraph("Data/graphic/chara/chara1/face4.png");
	charaSprite[1].face[5] = LoadGraph("Data/graphic/chara/chara1/face5.png");
	charaSprite[1].face[6] = LoadGraph("Data/graphic/chara/chara1/face6.png");
	charaSprite[1].face[7] = LoadGraph("Data/graphic/chara/chara1/face7.png");
	charaSprite[1].face[8] = LoadGraph("Data/graphic/chara/chara1/face8.png");
	charaSprite[1].face[9] = LoadGraph("Data/graphic/chara/chara1/face9.png");

	charaSprite[1].icon[1] = LoadGraph("Data/graphic/chara/chara1/icon1.png");
	charaSprite[1].icon[2] = LoadGraph("Data/graphic/chara/chara1/icon2.png");
	charaSprite[1].icon[3] = LoadGraph("Data/graphic/chara/chara1/icon3.png");

	mCG = -1;

	mSoundMessage = LoadSoundMem("Data/se/button68.mp3");
	mSE[0] = LoadSoundMem("Data/se/sceneswitch1.mp3");
}

void NovelScene::LoadFile() {
	std::ifstream ifs;
	std::string str;

	ifs.open("Data/novel/1-1.txt");

	if (ifs) {
		//��s�̓ǂݔ�΂�
		std::getline(ifs, str);

		while (!ifs.eof()) {
			std::getline(ifs, str);
			Buffer.push_back(str);
		}
	}
	ifs.close();
}

void NovelScene::Process() {
	mController.ConvertInput();

	if (mController.getKey(3) == 1 || mController.getKey(4) % 5 == 1) {
		Read();
	}

	DoCommand();

	//�\���ӏ���i�߂�
	if ((int)line[mCurrentLine].size() > mPoint[mCurrentLine]) {
		mPoint[mCurrentLine]++;
	}
	else if(mCurrentLine < 2){
		mCurrentLine++;
	}
}

void NovelScene::Read() {
	//�R�}���h�����͂��ꂽ�Ƃ�
	mReadAfterCommand = true;

	while (1) {
		if (!strcmp(Buffer[mBufferLine].substr(0, 2).c_str(), "cm") && flagAllowCommand) {

			//�R�}���h��o�b�t�@���[�h���I�t�ɂ���
			mReadAfterCommand = false;

			//�R�}���h��ǂݎ��s����
			ReadCommand(Buffer[mBufferLine]);

			mBufferLine++;
		}
		else break;
	}

	//�o�b�t�@����3�s�ǂݍ���
	if (mReadAfterCommand && flagAllowEnter) {
		ReadFromBuffer();
		PlaySoundMem(mSoundMessage, DX_PLAYTYPE_BACK);
	}
}

void NovelScene::ReadFromBuffer() {

	//�\���ӏ��̃��Z�b�g
	for (int i = 0; i < 3; i++) {
		mPoint[i] = 0;
		line[i].clear();
	}
	mAddCount = 0;

	//�o�b�t�@����X���b�g�ɓǂݍ��݁A�o�b�t�@��ǂݐi�߂�
	for (int i = 0; i < 3; i++) {
		line[i] = Buffer[i + mBufferLine];
		if (strcmp(line[i].c_str(), ""))mAddCount++;
		else break;
	}
	mBufferLine += mAddCount + 1;
	mCurrentLine = 0;
}

void NovelScene::ReadCommand(std::string command) {
	string pass;

	//�l�[���R�}���h
	if (!strcmp(command.substr(2, 4).c_str(), "name")){
		mNameId = Utility::StringToInt(command.substr(6, 1).c_str());
		mReadAfterCommand = true;
	}

	//�L�����R�}���h
	if (!strcmp(command.substr(2, 5).c_str(), "chara")) {
		mChara[1].charaId = Utility::StringToInt(command.substr(7, 1).c_str());
		mChara[1].faceId = 1;
		mReadAfterCommand = true;
	}

	//�L���������R�}���h
	if (!strcmp(command.substr(2, 8).c_str(), "characlr")) {
		mChara[1].charaId = 0;
		mChara[1].faceId = 0;
		mChara[1].iconId = 0;
		mReadAfterCommand = true;
	}

	//�\��R�}���h
	if (!strcmp(command.substr(2, 4).c_str(), "face")) {
		mChara[1].faceId = Utility::StringToInt(command.substr(6, 1).c_str());
		mReadAfterCommand = true;
	}

	//�A�C�R���R�}���h
	if (!strcmp(command.substr(2, 4).c_str(), "icon")) {
		mChara[1].iconId = Utility::StringToInt(command.substr(6, 1).c_str());
		mReadAfterCommand = true;
	}


	//�w�i�R�}���h
	if (!strcmp(command.substr(2, 3).c_str(), "bgg")) {
		mBGId = Utility::StringToInt(command.substr(5, 1).c_str());
		mReadAfterCommand = true;
	}

	//SE�R�}���h
	if (!strcmp(command.substr(2, 2).c_str(), "se")) {
		PlaySoundMem(mSE[Utility::StringToInt(command.substr(4, 1).c_str())], DX_PLAYTYPE_BACK);
		mReadAfterCommand = true;
	}

	//BGM�Đ��R�}���h
	if (!strcmp(command.substr(2, 3).c_str(), "bgm")) {
		pass = "Data/bgm/novel" + command.substr(5, 1) + ".mp3";
		if (CheckSoundMem(mBGM))StopSoundMem(mBGM);
		mBGM = LoadSoundMem(pass.c_str());
		PlaySoundMem(mBGM, DX_PLAYTYPE_LOOP);
		mReadAfterCommand = true;
	}

	//BGM��~�R�}���h
	if (!strcmp(command.substr(2, 7).c_str(), "stopbgm")) {
		if (CheckSoundMem(mBGM))StopSoundMem(mBGM);
		mReadAfterCommand = true;
	}

	//�S��ʈÓ]�R�}���h
	if (!strcmp(command.substr(2, 7).c_str(), "allbout")) {
		flagAllBlackout = true;
		flagAllowEnter = false;
		flagAllowCommand = false;
		for (int i = 0; i < 3; i++)line[i].clear();
		mNameId = 0;
	}

	//�S��ʈÓ]�����R�}���h
	if (!strcmp(command.substr(2, 10).c_str(), "clrallbout")) {
		flagAllBlackout = false;
		flagAllowEnter = false;
		flagAllowCommand = false;
	}

	//CG�\���R�}���h
	if (!strcmp(command.substr(2, 2).c_str(), "cg")) {
		pass = "Data/graphic/cg/cg";
		pass += command.substr(4, 1);
		pass += ".png";
		mCG = LoadGraph(pass.c_str());
		mReadAfterCommand = true;
	}

	//CG��\���R�}���h
	if (!strcmp(command.substr(2, 5).c_str(), "clrcg")) {
		DeleteGraph(mCG);
		mCG = -1;
		mReadAfterCommand = true;
	}

	//�`���v�^�[�^�C�g���\���R�}���h
	if (!strcmp(command.substr(2, 7).c_str(), "chapter")) {
		pass = "Data/graphic/chapter/chapter";
		pass += command.substr(9, 1);
		pass += ".png";
		mChapterGraph = LoadGraph(pass.c_str());
		mReadAfterCommand = true;
	}

	//�`���v�^�[�^�C�g����\���R�}���h
	if (!strcmp(command.substr(2, 10).c_str(), "clrchapter")) {
		DeleteGraph(mChapterGraph);
		mChapterGraph = -1;
		mReadAfterCommand = true;
	}



	//�E�F�C�g
	if (!strcmp(command.substr(2, 4).c_str(), "wait")) {
		mWaitcounter = Utility::StringToInt(command.substr(6, 3).c_str());
		flagAllowEnter = false;
		flagAllowCommand = false;
	}
}

void NovelScene::DoCommand() {
	//�S��ʈÓ]�����R�}���h
	if (!flagAllBlackout) {
		if (mAllBlackoutLevel > 5)mAllBlackoutLevel -= 5;
		if (mAllBlackoutLevel == 5) {
			flagAllowEnter = true;
			flagAllowCommand = true;
			mAllBlackoutLevel = 0;
			Read();
		}
	}

	//�S��ʈÓ]�R�}���h
	if (flagAllBlackout) {
		if (mAllBlackoutLevel < 255)mAllBlackoutLevel += 5;
		if (mAllBlackoutLevel == 250) {
			flagAllowEnter = true;
			flagAllowCommand = true;
			mAllBlackoutLevel = 255;
			Read();
		}
	}

	//�E�F�C�g�R�}���h
	if (mWaitcounter) {
		mWaitcounter--;
		if (mWaitcounter == 1) {
			mWaitcounter = 0;
			flagAllowEnter = true;
			flagAllowCommand = true;
			Read();
		}
	}
}

void NovelScene::Drawing() {
	//�w�i
	DrawGraph(0, 0, mBackGround[mBGId], 0);

	//�L���������G
	if (mChara[1].charaId) {
		DrawGraph(640 - 200, 0, charaSprite[mChara[1].charaId].base, true);
		if (mChara[1].faceId)DrawGraph(640 - 200, 0, charaSprite[mChara[1].charaId].face[mChara[1].faceId], true);
		if (mChara[1].iconId)DrawGraph(640 - 200, 0, charaSprite[mChara[1].charaId].icon[mChara[1].iconId], true);
	}

	//CG
	if (mCG != -1) {
		DrawGraph(0, 0, mCG, 1);
	}

	DrawGraph(0, 0, mWindow, 1);

	//�L������
	DrawFormatStringToHandle(150, 480, Parameter::COLOR_WHITE, Parameter::FONT_40, name[mNameId].c_str());
	//DrawFormatString(100, 180, Parameter::COLOR_RED, "buffer %d length %d", mBufferLine, Buffer.size());
	
	//���͕\��
	for (int i = 0; i < 3; i++) {
		//DrawFormatString(100, 210 + i * 35, Parameter::COLOR_RED,"test %d %d %d",mCurrentLine,line[i].size(),mPoint[i]);
		//if (!strcmp(line[i].c_str(), ""))break;
		DrawFormatStringToHandle(150, 540 + i * 45, Parameter::COLOR_WHITE, Parameter::FONT_40, line[i].substr(0, mPoint[i]).c_str());
	}

	//DrawFormatStringToHandle(180, 440 + 0 * 45, Parameter::COLOR_WHITE, Parameter::FONT_40, line[0].substr(0, 2).c_str());

	//�`���v�^�[�^�C�g��
	if (mChapterGraph != -1) {
		DrawGraph(0, 0, mChapterGraph, 1);
	}

	//�S��ʈÓ]�̕`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, mAllBlackoutLevel);
	DrawBox(0, 0, Parameter::WINDOW_WIDTH, Parameter::WINDOW_HEIGHT, Parameter::COLOR_BLACK, 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}