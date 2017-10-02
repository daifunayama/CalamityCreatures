#include "Camera.h"
#include "../Parameter.h"

void Camera::Init() {
	mPositionX = - 500 - Parameter::WINDOW_WIDTH / 2;
	mPositionY = 600-Parameter::WINDOW_HEIGHT / 2 - 100;
	quakeX = 0;
	quakeY = 0;
	quakeCounter = 0;
}

void Camera::Follow(int pX, int pY, int speed) {
	double distX, distY, distAngle, moveX, moveY, speedX, speedY;

	distX = (double)(pX - mPositionX);
	distY = (double)(pY - mPositionY);

	if (-30 < distX && distX < 30)distX = 0;
	if (-30 < distY && distY < 30)distY = 0;

	distAngle = atan2(distY, distX);

	if (distX > 270 || distX < -270) {
		speedX = speed;
	}
	else speedX = abs(distX / 5);

	if (distY > 270 || distY < -270) {
		speedY = speed;
	}
	else speedY = abs(distY / 5);

	//else speedY = abs(distY / 10);

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
		Follow(moveX, moveY,30);
	}

	else {
		//mPositionX = p1.getPositionX() - Parameter::WINDOW_WIDTH / 2;

		//if (p1.getPositionY() > Parameter::WINDOW_HEIGHT / 2)mPositionY = 0;
		//else mPositionY = p1.getPositionY() - Parameter::WINDOW_HEIGHT / 2;

		Follow(moveX, moveY, 30);
	}

	QuakeWindow();
}

void Camera::SetQuakeWindow(int counter, int level) {
	quakeCounter = counter;
	quakeLevel = level;
}

void Camera::QuakeWindow() {
	if (quakeCounter > 0) {

		//quakeX = sin(quakeCounter * Parameter::PI / 180) * 20;
		quakeY = cos(quakeCounter * 50 * Parameter::PI / 180) * quakeLevel;

		quakeCounter--;
	}
	else {
		quakeLevel = 0;
		quakeX = 0;
		quakeY = 0;
	}
}