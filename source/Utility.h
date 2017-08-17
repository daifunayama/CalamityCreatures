#pragma once
#include "SSPlayer\SS5Player.h"
#include <string>
#include <sstream>
#include "DxLib.h"

/*
汎用関数の定義クラス
*/
class Utility {
public:
	/*intをstringに変換*/
	static std::string IntToString(int n) {
		std::stringstream ss;
		ss << n;
		return ss.str();
	}

	/*stringをintに変換*/
	static int StringToInt(std::string str) {
		int n;
		std::stringstream ss;
		ss << str;
		ss >> n;
		return n;
	}

	static bool CheckQuadPointHit(ss::Quad quad, int x, int y) {
		float aX,aY,a,b;
		bool t[4];
		
		aX = quad.tl.x - quad.bl.x;
		aY = quad.tl.y - quad.bl.y;

		if (aX != 0) {
			a = aY / aX;
			b = quad.tl.y - a * quad.tl.x;

			if (a * (float)x + b > (float)y) {
				t[0] = true;
				//DrawString(10, 10, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (x > quad.tl.x) {
				t[0] = true;
				//DrawString(10, 10, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		aX = quad.tr.x - quad.br.x;
		aY = quad.tr.y - quad.br.y;

		if (aX != 0) {
			a = aY / aX;
			b = quad.tr.y - a * quad.tr.x;

			if (a * (float)x + b < (float)y) {
				t[1] = true;
				//DrawString(10, 30, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (x < quad.tr.x) {
				t[1] = true;
				//DrawString(10, 30, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		aX = quad.tr.x - quad.tl.x;
		aY = quad.tr.y - quad.tl.y;

		if (aY != 0) {
			a = aY / aX;
			b = quad.tl.y - a * quad.tl.x;

			if (a * (float)x + b < (float)y) {
				t[2] = true;
				//DrawString(10, 50, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (y > quad.tl.y) {
				t[2] = true;
				//DrawString(10, 50, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		aX = quad.br.x - quad.bl.x;
		aY = quad.br.y - quad.bl.y;

		if (aY != 0) {
			a = aY / aX;
			b = quad.bl.y - a * quad.bl.x;

			if (a * (float)x + b > (float)y) {
				t[3] = true;
				//DrawString(10, 70, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (y < quad.bl.y) {
				t[3] = true;
				//DrawString(10, 70, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		if(t[0] && t[1] && t[2] && t[3])return true;
		return false;
	}
};