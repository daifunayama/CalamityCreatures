#pragma once
#include "SSPlayer\SS5Player.h"
#include <string>
#include <sstream>
#include "DxLib.h"

/*
�ėp�֐��̒�`�N���X
*/
class Utility {
public:
	/*int��string�ɕϊ�*/
	static std::string IntToString(int n) {
		std::stringstream ss;
		ss << n;
		return ss.str();
	}

	/*string��int�ɕϊ�*/
	static int StringToInt(std::string str) {
		int n;
		std::stringstream ss;
		ss << str;
		ss >> n;
		return n;
	}
	
	static bool CheckQuadPointHit(Quad quad, int x, int y) {
		float aX,aY,a,b;
		bool t[4];
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
		t[3] = 0;
		
		Quad mQuad;

		if (quad.tl.x == quad.bl.x) {
			if (quad.tl.x < x && x < quad.tr.x && quad.tl.y < y && y < quad.bl.y)return true;
			else return false;
		}

		/*�@�@�@�Ztr
		�Ztl
		
		�@�@�@�@�@�Zbr
		�@�Zbl
		*/
		if (quad.tl.x < quad.bl.x && quad.tl.x <= quad.tr.x) {
			mQuad = quad;
		}
		/*�@�@�@�Zbr
		�Ztr

		�@�@�@�@�@�Zbl
		�@�Ztl
		*/
		else if (quad.tl.x > quad.tr.x && quad.tl.x < quad.br.x) {
			mQuad.tl = quad.tr;
			mQuad.tr = quad.br;
			mQuad.br = quad.bl;
			mQuad.bl = quad.tl;
		}
		/*�@�@�@�Zbl
		�Zbr

		�@�@�@�@�@�Ztl
		�@�Ztr
		*/
		else if(quad.tl.x > quad.tr.x && quad.tl.x > quad.bl.x){
			mQuad.tl = quad.br;
			mQuad.br = quad.tl;
			mQuad.tr = quad.bl;
			mQuad.bl = quad.tr;
		}
		/*�@�@�@�Ztl
		�Zbl

		�@�@�@�@�@�Ztr
		�@�Zbr
		*/
		else {
			mQuad.tl = quad.bl;
			mQuad.bl = quad.br;
			mQuad.br = quad.tr;
			mQuad.tr = quad.tl;
		}

		aX = mQuad.tl.x - mQuad.bl.x;
		aY = mQuad.tl.y - mQuad.bl.y;

		if (aX != 0) {
			a = aY / aX;
			b = mQuad.tl.y - a * mQuad.tl.x;

			if (a * (float)x + b > (float)y) {
				t[0] = true;
				//DrawString(10, 10, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (x > mQuad.tl.x) {
				t[0] = true;
				//DrawString(10, 10, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		aX = mQuad.tr.x - mQuad.br.x;
		aY = mQuad.tr.y - mQuad.br.y;

		if (aX != 0) {
			a = aY / aX;
			b = mQuad.tr.y - a * mQuad.tr.x;

			if (a * (float)x + b < (float)y) {
				t[1] = true;
				//DrawString(10, 30, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (x < mQuad.tr.x) {
				t[1] = true;
				//DrawString(10, 30, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		aX = mQuad.tr.x - mQuad.tl.x;
		aY = mQuad.tr.y - mQuad.tl.y;

		if (aY != 0) {
			a = aY / aX;
			b = mQuad.tl.y - a * mQuad.tl.x;

			if (a * (float)x + b < (float)y) {
				t[2] = true;
				//DrawString(10, 50, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (y > mQuad.tl.y) {
				t[2] = true;
				//DrawString(10, 50, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		aX = mQuad.br.x - mQuad.bl.x;
		aY = mQuad.br.y - mQuad.bl.y;

		if (aY != 0) {
			a = aY / aX;
			b = mQuad.bl.y - a * mQuad.bl.x;

			if (a * (float)x + b > (float)y) {
				t[3] = true;
				//DrawString(10, 70, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}
		else {
			if (y < mQuad.bl.y) {
				t[3] = true;
				//DrawString(10, 70, "HIT", Parameter::COLOR_WHITE, 0);
			}
		}

		if(t[0] && t[1] && t[2] && t[3])return true;
		return false;
	}
	
};