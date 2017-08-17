#include "DxLib.h"
#include "Application.h"
#include "Parameter.h"
#include <math.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	SetOutApplicationLogValidFlag(false);

	//画面の設定
	ChangeWindowMode(true);
	SetMainWindowText("");
	SetWindowSizeChangeEnableFlag(false);
	SetGraphMode(Parameter::WINDOW_WIDTH, Parameter::WINDOW_HEIGHT, 32);
	SetWindowSizeExtendRate(1);

	if (DxLib_Init() == -1)return -1;

	SetDrawScreen(DX_SCREEN_BACK);

	SetDrawMode(DX_DRAWMODE_BILINEAR);

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);

	int t0;

	Application application;

	//メインループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		t0 = GetNowCount();   //ループ前の時間の取得

		ClearDrawScreen();    //画面のクリア


		//メインループ
		application.MainLoop();

		//60FPSに調整
		while ((GetNowCount() - t0) <= (double)(1000 / 60)) {}

		ScreenFlip(); //スクリーンに表示
	}

	DxLib_End();// ＤＸライブラリ使用の終了処理

	return 0;// ソフトの終了 

}
