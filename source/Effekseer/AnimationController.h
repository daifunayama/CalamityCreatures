#pragma once
#include "EffAnimation.h"
#include <vector>

/*
Effekseerアニメーションの制御を行うシングルトンパターンクラス
*/
class AnimationController {
public:
	static AnimationController& getInstance(void) {
		static AnimationController animationController;
		return animationController;
	}
	AnimationController(const AnimationController&) = delete;
	AnimationController& operator = (const AnimationController&) = delete;
	AnimationController(AnimationController&&) = delete;
	AnimationController operator = (AnimationController&&) = delete;

	int Create(int gHandle, int layer, int x, int y, int width, int height, float exRate, int angle,
		int devided, int speed, int endFrame, int loopFrame, bool right, bool addFrag);
	void Process();
	void SetPosition(int id, int x, int y);
	void Remove(int id);
	void Reset();
	void Draw();
	void DrawLayer1();
	void DrawLayer2();
	void DrawLayer3();

private:
	AnimationController() {}
	~AnimationController() {}

private:
	std::vector<EffAnimation> mEffAnimation;	//アニメーション制御配列
	int mKey;									//アニメーションにわたすキー
};