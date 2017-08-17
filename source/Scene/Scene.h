#pragma once

/*
各シーンの基本となるクラス
*/
class Scene {
public:
	Scene(int id) :mSceneId(id) {}
	virtual void Load() = 0;
	virtual void Process() = 0;
	virtual void Drawing() = 0;

private:
	const int mSceneId;		//シーンのID
};