#include "Input.h"
#include "DxLib.h"

/*入力情報の更新*/
void Input::Update() {
	char Buf[256];

	GetHitKeyStateAll(Buf);

	mKey[KEY_INPUT_Z] = (Buf[KEY_INPUT_Z] == 1) ? mKey[KEY_INPUT_Z] + 1 : 0;
	mKey[KEY_INPUT_X] = (Buf[KEY_INPUT_X] == 1) ? mKey[KEY_INPUT_X] + 1 : 0;
	mKey[KEY_INPUT_C] = (Buf[KEY_INPUT_C] == 1) ? mKey[KEY_INPUT_C] + 1 : 0;
	mKey[KEY_INPUT_V] = (Buf[KEY_INPUT_V] == 1) ? mKey[KEY_INPUT_V] + 1 : 0;
	mKey[KEY_INPUT_B] = (Buf[KEY_INPUT_B] == 1) ? mKey[KEY_INPUT_B] + 1 : 0;
	mKey[KEY_INPUT_N] = (Buf[KEY_INPUT_N] == 1) ? mKey[KEY_INPUT_N] + 1 : 0;
	mKey[KEY_INPUT_M] = (Buf[KEY_INPUT_M] == 1) ? mKey[KEY_INPUT_M] + 1 : 0;

	mKey[KEY_INPUT_I] = (Buf[KEY_INPUT_I] == 1) ? mKey[KEY_INPUT_I] + 1 : 0;
	mKey[KEY_INPUT_J] = (Buf[KEY_INPUT_J] == 1) ? mKey[KEY_INPUT_J] + 1 : 0;
	mKey[KEY_INPUT_K] = (Buf[KEY_INPUT_K] == 1) ? mKey[KEY_INPUT_K] + 1 : 0;
	mKey[KEY_INPUT_L] = (Buf[KEY_INPUT_L] == 1) ? mKey[KEY_INPUT_L] + 1 : 0;
	mKey[KEY_INPUT_G] = (Buf[KEY_INPUT_G] == 1) ? mKey[KEY_INPUT_G] + 1 : 0;
	mKey[KEY_INPUT_F] = (Buf[KEY_INPUT_F] == 1) ? mKey[KEY_INPUT_F] + 1 : 0;
	mKey[KEY_INPUT_A] = (Buf[KEY_INPUT_A] == 1) ? mKey[KEY_INPUT_A] + 1 : 0;
	mKey[KEY_INPUT_RETURN] = (Buf[KEY_INPUT_RETURN] == 1) ? mKey[KEY_INPUT_RETURN] + 1 : 0;

	if (GetJoypadNum() == 1) {
		mKey[PAD_INPUT_UP] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP)) ? mKey[PAD_INPUT_UP] + 1 : 0;
		mKey[PAD_INPUT_DOWN] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN)) ? mKey[PAD_INPUT_DOWN] + 1 : 0;
		mKey[PAD_INPUT_RIGHT] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT)) ? mKey[PAD_INPUT_RIGHT] + 1 : 0;
		mKey[PAD_INPUT_LEFT] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT)) ? mKey[PAD_INPUT_LEFT] + 1 : 0;

		mKey[PAD_INPUT_1] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4)) ? mKey[PAD_INPUT_1] + 1 : 0;
		mKey[PAD_INPUT_2] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_1)) ? mKey[PAD_INPUT_2] + 1 : 0;
		mKey[PAD_INPUT_3] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_2)) ? mKey[PAD_INPUT_3] + 1 : 0;
		mKey[PAD_INPUT_4] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_3)) ? mKey[PAD_INPUT_4] + 1 : 0;
		mKey[PAD_INPUT_5] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_6)) ? mKey[PAD_INPUT_5] + 1 : 0;
		mKey[PAD_INPUT_6] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_8)) ? mKey[PAD_INPUT_6] + 1 : 0;
		mKey[PAD_INPUT_7] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_5)) ? mKey[PAD_INPUT_7] + 1 : 0;
		mKey[PAD_INPUT_8] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_7)) ? mKey[PAD_INPUT_8] + 1 : 0;
		mKey[PAD_INPUT_9] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_9)) ? mKey[PAD_INPUT_9] + 1 : 0;
		mKey[PAD_INPUT_10] = ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_10)) ? mKey[PAD_INPUT_10] + 1 : 0;
	}
	else {
		mKey[KEY_INPUT_UP] = (Buf[KEY_INPUT_UP] == 1) ? mKey[KEY_INPUT_UP] + 1 : 0;
		mKey[KEY_INPUT_DOWN] = (Buf[KEY_INPUT_DOWN] == 1) ? mKey[KEY_INPUT_DOWN] + 1 : 0;
		mKey[KEY_INPUT_RIGHT] = (Buf[KEY_INPUT_RIGHT] == 1) ? mKey[KEY_INPUT_RIGHT] + 1 : 0;
		mKey[KEY_INPUT_LEFT] = (Buf[KEY_INPUT_LEFT] == 1) ? mKey[KEY_INPUT_LEFT] + 1 : 0;

		mKey[KEY_INPUT_1] = (Buf[KEY_INPUT_1] == 1) ? mKey[KEY_INPUT_1] + 1 : 0;
		mKey[KEY_INPUT_2] = (Buf[KEY_INPUT_2] == 1) ? mKey[KEY_INPUT_2] + 1 : 0;
		mKey[KEY_INPUT_3] = (Buf[KEY_INPUT_3] == 1) ? mKey[KEY_INPUT_3] + 1 : 0;
		mKey[KEY_INPUT_4] = (Buf[KEY_INPUT_4] == 1) ? mKey[KEY_INPUT_4] + 1 : 0;
		mKey[KEY_INPUT_5] = (Buf[KEY_INPUT_5] == 1) ? mKey[KEY_INPUT_5] + 1 : 0;
		mKey[KEY_INPUT_6] = (Buf[KEY_INPUT_6] == 1) ? mKey[KEY_INPUT_6] + 1 : 0;
		mKey[KEY_INPUT_7] = (Buf[KEY_INPUT_7] == 1) ? mKey[KEY_INPUT_7] + 1 : 0;
		mKey[KEY_INPUT_8] = (Buf[KEY_INPUT_8] == 1) ? mKey[KEY_INPUT_8] + 1 : 0;
		mKey[KEY_INPUT_9] = (Buf[KEY_INPUT_9] == 1) ? mKey[KEY_INPUT_9] + 1 : 0;
		mKey[KEY_INPUT_0] = (Buf[KEY_INPUT_0] == 1) ? mKey[KEY_INPUT_0] + 1 : 0;
	}
}

/*キーの入力情報の取得*/
int Input::GetKey(int key) {
	return mKey[key];
}
