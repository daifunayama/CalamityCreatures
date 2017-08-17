#pragma once
#include "../SSPlayer/SS5Player.h"
#include "../Quad/Quad.h"

/*
�G�𐧌䂷��N���X
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