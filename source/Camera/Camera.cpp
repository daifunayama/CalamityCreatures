#include "Camera.h"
#include "../Parameter.h"

void Camera::Init() {
	mPositionX = 0;
	mPositionY = 0;
}

void Camera::Follow(int pX, int pY, int speed) {
	double distX, distY, distAngle, moveX, moveY, speedX, speedY;

	distX = (double)(pX - mPositionX);
	distY = (double)(pY - mPositionY);

	if (-10 < distX && distX < 10)distX = 0;
	if (-10 < distY && distY < 10)distY = 0;

	distAngle = atan2(distY, distX);

	if (distX > 170 || distX < -170) {
		speedX = speed;
	}
	else speedX = abs(distX / 10);

	if (distY > 170 || distY < -170) {
		speedY = 50;
	}
	else if (distY > 70 || distY < -70) {
		speedY = 20;
	}
	else speedY = abs(distY / 10);

	moveX = (double)cos(distAngle) * speedX;
	moveY = (double)sin(distAngle) * speedY;

	if (distX == 0)moveX = 0;
	if (distY == 0)moveY = 0;

	mPositionX += (int)moveX;
	mPositionY += (int)moveY;
}

void Camera::Update(Player p1, Enemy enemy) {
	float pX, pY;
	int moveX, moveY;
	
	pX = p1.getSprite()->getPositionX();
	pY = p1.getSprite()->getPositionY();

	moveX = p1.getPositionX() - Parameter::WINDOW_WIDTH / 2;
	moveY = p1.getPositionY() - Parameter::WINDOW_HEIGHT / 2 - 100;

	if (p1.getController().getKey(8)){
		moveX = enemy.getPositionX() - Parameter::WINDOW_WIDTH / 2;
		moveY = enemy.getPositionY() - Parameter::WINDOW_HEIGHT / 2 - 100;
	}

	if (p1.getState() == Parameter::S_PLAYER_CATCH) {
		Follow(moveX, moveY,10);
	}

	else {
		//mPositionX = p1.getPositionX() - Parameter::WINDOW_WIDTH / 2;

		//if (p1.getPositionY() > Parameter::WINDOW_HEIGHT / 2)mPositionY = 0;
		//else mPositionY = p1.getPositionY() - Parameter::WINDOW_HEIGHT / 2;

		Follow(moveX, moveY, 30);
	}

}

