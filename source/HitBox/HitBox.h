#pragma once
class HitBox {
public:
	HitBox(){}
	HitBox(int width, int height);
	void SetPosition(int x, int y);
	void Draw(int color);

	static bool CheckHit(HitBox box1, HitBox box2);

private:
	int x, y, width, height;
};