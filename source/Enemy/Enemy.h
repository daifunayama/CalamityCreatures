#pragma once
#include "../SSPlayer/SS5Player.h"
#include "../Quad/Quad.h"

/*
“G‚ğ§Œä‚·‚éƒNƒ‰ƒX
*/
class Enemy {
public:
	Quad getQuad(const char* name);

	void LoadGraphic();
	void Process();
	void Draw();

private:
	ss::Player *mSprite;
};