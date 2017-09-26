#pragma once
#include "../Player/Player.h"

class Player;

/*
�J�����̐�����s���V���O���g���p�^�[���N���X
*/
class Camera {
public:
	static Camera& getInstance(void) {
		static Camera camera;
		return camera;
	}
	Camera(const Camera&) = delete;
	Camera& operator = (const Camera&) = delete;
	Camera(Camera&&) = delete;
	Camera operator = (Camera&&) = delete;

	inline int getPositonX() { return mPositionX + quakeX; }
	inline int getPositonY() { return mPositionY + quakeY; }
	inline int getCenterX() { return mCenterX; }
	inline int getCenterY() { return mCenterY; }

	inline void setPositonX(int positionX) { mPositionX = positionX; }
	inline void setPositonY(int positionY) { mPositionY = positionY; }
	inline void setCenterX(int centerX) { mCenterX = centerX; }
	inline void setCenterY(int centerY) { mCenterY = centerY; }
	void Init();
	void Update(Player p1, Enemy enemy);

	void SetQuakeWindow(int counter, int level);
	void QuakeWindow();

private:
	int mPositionX;		//�J������X���W
	int mPositionY;		//�J������Y���W
	int mCenterX;		//��ʒ�����X���W
	int mCenterY;		//��ʒ�����Y���W
	float quakeX;
	float quakeY;
	int quakeCounter;
	int quakeLevel;

private:
	void Follow(int, int,int);
	Camera() {}
	~Camera() {}
};