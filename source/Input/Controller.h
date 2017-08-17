#pragma once

/*
各プレイヤー用の入力キーの変換クラス
*/
class Controller {
public:
	void ConvertInput();

	inline int getKey(int key) { return pushKey[key]; }
	inline int getUp() { return pushUp; }
	inline int getDown() { return pushDown; }
	inline int getRight() { return pushRight; }
	inline int getLeft() { return pushLeft; }

private:
	int pushKey[12];	//各ボタン
	int pushUp;			//上キー
	int pushDown;		//下キー
	int pushRight;		//右キー
	int pushLeft;		//左キー
};