#include "HitBox.h"
#include "../Parameter.h"
#include "../Camera/Camera.h"
#include "DxLib.h"

HitBox::HitBox(int w, int h) {
	width = w;
	height = h;
}

void HitBox::SetPosition(int mx, int my) {
	x = mx - width / 2;
	y = my - height / 2;
}

bool HitBox::CheckHit(HitBox box1, HitBox box2) {
	if (box1.x <= box2.x + box2.width && box2.x <= box1.x + box1.width &&
		box1.y <= box2.y + box2.height && box2.y <= box1.y + box1.height)return true;
	
	return false;
}

void HitBox::Draw(int color) {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);

	DrawBox(x - Camera::getInstance().getPositonX(), y - Camera::getInstance().getPositonY(),
		x + width - Camera::getInstance().getPositonX(), y + height - Camera::getInstance().getPositonY(),color, 1);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}