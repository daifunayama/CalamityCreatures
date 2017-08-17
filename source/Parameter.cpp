#include "Parameter.h"
#include "DxLib.h"

const float Parameter::PI = 3.1415926535897932384626433832795f;

int Parameter::FONT_5  = -1;
int Parameter::FONT_10 = -1;
int Parameter::FONT_12 = -1;
int Parameter::FONT_15 = -1;
int Parameter::FONT_20 = -1;
int Parameter::FONT_20_FERRUM = -1;
int Parameter::FONT_30 = -1;
int Parameter::FONT_50_FERRUM = -1;
int Parameter::FONT_80_FERRUM = -1;
int Parameter::FONT_100_FERRUM = -1;
int Parameter::FONT_120_FERRUM = -1;

//色定義
const int Parameter::COLOR_WHITE = GetColor(255,255,255);
const int Parameter::COLOR_BLACK = GetColor(0,0,0);
const int Parameter::COLOR_RED = GetColor(255,0,0);
const int Parameter::COLOR_BLUE = GetColor(0,0,255);
const int Parameter::COLOR_GREEN = GetColor(0,255,0);
const int Parameter::COLOR_YELLOW = GetColor(255, 255, 0);

/*フォントの作成*/
void Parameter::InitFont() {
	Parameter::FONT_5 = CreateFontToHandle(NULL, 5, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_10 = CreateFontToHandle(NULL, 10, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_12 = CreateFontToHandle(NULL, 12, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_15 = CreateFontToHandle(NULL, 15, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_20 = CreateFontToHandle(NULL, 20, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_20_FERRUM = CreateFontToHandle("Ferrum", 20, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_30 = CreateFontToHandle(NULL, 30, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_50_FERRUM = CreateFontToHandle("Ferrum", 50, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_80_FERRUM = CreateFontToHandle("Ferrum", 60, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_100_FERRUM = CreateFontToHandle("Ferrum", 100, 8, DX_FONTTYPE_ANTIALIASING_4X4);
	Parameter::FONT_120_FERRUM = CreateFontToHandle("Ferrum", 120, 8, DX_FONTTYPE_ANTIALIASING_4X4);
}