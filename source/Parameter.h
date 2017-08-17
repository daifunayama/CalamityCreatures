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
	static int FONT_50_FERRUM;
	static int FONT_80_FERRUM;
	static int FONT_100_FERRUM;
	static int FONT_120_FERRUM;

	//シーンID
	static const int SCENE_TITLE = 1;
	static const int SCENE_CHARASELECT = 2;
	static const int SCENE_CONTRACT = 3;
	static const int SCENE_EYECATCH = 4;
	static const int SCENE_BATTLE = 5;

	//魔具のカテゴリID
	static const int HK = 0;
	static const int CM = 1;
	static const int MG = 2;
	static const int YT = 3;
	static const int HC = 4;
	static const int EA = 5;
	static const int AA = 6;
	static const int HR = 7;
	static const int MJ = 8;
	static const int PS = 9;


	//プレイヤーの状態
	static const int S_PLAYER_NORMAL = 1;
	static const int S_PLAYER_WALK = 2;
	static const int S_PLAYER_BACK = 3;
	static const int S_PLAYER_SQUAT = 4;
	static const int S_PLAYER_JUMP = 5;
	static const int S_PLAYER_DAMAGE_U = 6;
	static const int S_PLAYER_DAMAGE_D = 7;
	static const int S_PLAYER_DAMAGE_AIR = 8;
	static const int S_PLAYER_DAMAGE_AIR2 = 9;
	static const int S_PLAYER_DAMAGE_S = 10;
	static const int S_PLAYER_SUMMON = 11;
	static const int S_PLAYER_DASH = 12;
	static const int S_PLAYER_STEP = 13;
	static const int S_PLAYER_GUARD = 14;
	static const int S_PLAYER_GUARD_S = 15;
	static const int S_PLAYER_STOP = 16;
	static const int S_PLAYER_DOWN = 17;
	static const int S_PLAYER_ATACK_A = 18;
	static const int S_PLAYER_ATACK_8A = 19;
	static const int S_PLAYER_ATACK_2A = 20;
	static const int S_PLAYER_ATACK_JA = 21;
	static const int S_PLAYER_ATACK_B = 22;
	static const int S_PLAYER_ATACK_8B = 23;
	static const int S_PLAYER_ATACK_2B = 24;
	static const int S_PLAYER_ATACK_JB = 25;
	static const int S_PLAYER_ATACK_3B = 26;
	static const int S_PLAYER_ATACK_6B = 27;
	static const int S_PLAYER_CATCH = 28;
	static const int S_PLAYER_CAUGHT = 29;
	static const int S_PLAYER_ESCAPE = 30;
	static const int S_PLAYER_THROW = 31;
	static const int S_PLAYER_BURST = 32;

	//魔具の状態
	static const int S_ARMS_NORMAL = 1;
	static const int S_ARMS_SUMMON = 10;
	static const int S_ARMS_ATACK_C = 2;
	static const int S_ARMS_ATACK_8C = 3;
	static const int S_ARMS_ATACK_2C = 4;
	static const int S_ARMS_ATACK_JC = 5;
	static const int S_ARMS_ATACK_D = 6;
	static const int S_ARMS_ATACK_8D = 7;
	static const int S_ARMS_ATACK_2D = 8;
	static const int S_ARMS_ATACK_JD = 9;

	//プレイヤーの攻撃
	static const int P_ATACK_A = 0;
	static const int P_ATACK_8A = 1;
	static const int P_ATACK_2A = 2;
	static const int P_ATACK_JA = 3;
	static const int P_ATACK_B = 4;
	static const int P_ATACK_8B = 5;
	static const int P_ATACK_2B = 6;
	static const int P_ATACK_JB = 7;
	static const int P_ATACK_3B = 8;
	static const int P_ATACK_6B = 9;
	static const int P_ATACK_THROW = 21;
	static const int P_ATACK_THROW_R = 22;
	static const int P_ATACK_THROW_AIR = 23;
	static const int P_ATACK_THROW_AIR_R = 24;

	//魔具の攻撃
	static const int ATACK_C  = 0;
	static const int ATACK_8C = 1;
	static const int ATACK_2C = 2;
	static const int ATACK_JC = 3;
	static const int ATACK_D  = 4;
	static const int ATACK_8D = 5;
	static const int ATACK_2D = 6;
	static const int ATACK_JD = 7;

	//画面定義
	static const int WINDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 720;
	static const int FIELD_WIDTH = 2000;
	static const int FIELD_HEIGHT = 1000;
	static const int GROUND_LINE = 700;

	//色定義
	static const int COLOR_WHITE;
	static const int COLOR_BLACK;
	static const int COLOR_RED;
	static const int COLOR_BLUE;
	static const int COLOR_GREEN;
	static const int COLOR_YELLOW;

	static void InitFont();
};