#pragma once

/*
Effekseerアニメーションのデータクラス
*/

class EffAnimation {
public:
	inline bool getExist() { return mExist; }
	inline int getKey() { return mKey; }
	inline int getAtackId() { return mAtackId; }
	inline int getState() { return mState; }
	inline int getLayer() { return mLayer; }
	inline int getGraph() { return mGraph; }
	inline int getPositionX() { return mPositionX; }
	inline int getPositionY() { return mPositionY; }
	inline int getWidth() { return mWidth; }
	inline int getHeight() { return mHeight; }
	inline float getExRate() { return mExRate; }
	inline int getDevided() { return mDevided; }
	inline int getSpeed() { return mSpeed; }
	inline int getAngle() { return mAngle; }
	inline int getCounter() { return mCounter; }
	inline int getStartFrame() { return mStartFrame; }
	inline int getEndFrame() { return mEndFrame; }
	inline int getLoopFrame() { return mLoopFrame; }
	inline bool getAddFlag() { return mAddFlag; }
	inline bool getRight(){ return mRight; }
	
	inline void setExist(int exist) { mExist = exist; }
	inline void setKey(int key) { mKey = key; }
	inline void setAtackId(int atackId) { mAtackId = atackId; }
	inline void setState(int state) { mState = state; }
	inline void setLayer(int layer) { mLayer = layer; }
	inline void setGraph(int graph) { mGraph = graph; }
	inline void setPositionX(int positionX) { mPositionX = positionX; }
	inline void setPositionY(int positionY) { mPositionY = positionY; }
	inline void setWidth(int width) { mWidth = width; }
	inline void setHeight(int height) { mHeight = height; }
	inline void setExRate(float exRate) { mExRate = exRate; }
	inline void setDevided(int devided) { mDevided = devided; }
	inline void setSpeed(int speed) { mSpeed = speed; }
	inline void setAngle(int angle) { mAngle = angle; }
	inline void setCounter(int counter) { mCounter = counter; }
	inline void setStartFrame(int startFrame) { mStartFrame = startFrame; }
	inline void setEndFrame(int endFrame) { mEndFrame = endFrame; }
	inline void setLoopFrame(int loopFrame) { mLoopFrame = loopFrame; }
	inline void setAddFlag(bool addFlag) { mAddFlag = addFlag; }
	inline void setRight(bool right) { mRight = right; }

	inline void IncrementCounter() { mCounter++; }

private:
	bool mExist;		//存在フラグ
	int mKey;			//アニメーションのキー
	int mAtackId;		//攻撃ID
	int mLayer;			//レイヤー
	int mState;			//状態変数
	int mGraph;			//グラフィックハンドル
	int mPositionX;		//X座標
	int mPositionY;		//Y座標
	int mWidth;			//横幅
	int mHeight;		//高さ
	float mExRate;		//拡大率
	int mDevided;		//元画像の横分割数
	int mSpeed;			//再生速度
	int mAngle;			//角度
	int mCounter;		//カウンター
	int mStartFrame;	//再生開始フレーム
	int mEndFrame;		//再生終了フレーム
	int mLoopFrame;		//ループアニメの場合のループフレーム(それ以外は-1)
	bool mAddFlag;		//加算描画フラグ
	bool mRight;		//向き
};