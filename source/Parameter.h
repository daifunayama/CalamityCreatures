#pragma once
#include "DxLib.h"

/*
ゲーム内の固定パラメータを定義するクラス
*/
class Parameter {
public:
	static const float PI;

	//フォント
	static int FONT_5;
	static int FONT_10;
	static int FONT_12;
	static int FONT_15;
	static int FONT_20;
	static int FONT_20_FERRUM;
	static int FONT_30;
	static int FONT_40;
	static int FONT_50_FERRUM;
	static int FONT_80_FERRUM;
	static int FONT_100_FERRUM;
	static int FONT_120_FERRUM;

	//シーンID
	static const int SCENE_TITLE = 1;
	static const int SCENE_NOVEL = 2;
	static const int SCENE_CONTRACT = 3;
	static const int SCENE_EYECATCH = 4;
	static const int SCENE_BATTLE = 5;


	//プレイヤーの状態
	static const int S_PLAYER_NORMAL = 1;
	static const int S_PLAYER_WALK = 2;
	static const int S_PLAYER_BACK = 3;
	static const int S_PLAYER_SQUAT = 4;
	static const int S_PLAYER_JUMP = 5;
	static const int S_PLAYER_CATCH = 28;
	static const int S_PLAYER_RIDE = 6;

	//画面定義
	static const int WINDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 720;
	static const int FIELD_WIDTH = 2000;
	static const int FIELD_HEIGHT = 1000;
	static const int GROUND_LINE = 700;

	//色定義
	static const int COLOR_WHITE;
	static const int COLOR_BLACK;
	static const int COLOR_GRAY;
	static const int COLOR_RED;
	static const int COLOR_BLUE;
	static const int COLOR_GREEN;
	static const int COLOR_YELLOW;

	static void InitFont();
};