#pragma once
#include <map>

/*
プレイヤーからの入力の制御を行うシングルトンパターンクラス
*/
class Input {
public:
	static Input& getInstance(void) {
		static Input input;
		return input;
	}
	Input(const Input&) = delete;
	Input& operator = (const Input&) = delete;
	Input(Input&&) = delete;
	Input operator = (Input&&) = delete;

	void Update();
	int GetKey(int key);

private:
	std::map<int,int> mKey;		//各キーへのマッピング用配列

private:
	Input(){}
	~Input(){}
};