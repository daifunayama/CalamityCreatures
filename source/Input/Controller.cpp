#include "Controller.h"
#include "Input.h"
#include "DxLib.h"

/*ì¸óÕèÓïÒÇÃïœä∑*/
void Controller::ConvertInput() {

	if (GetJoypadNum() == 1) {
		pushKey[1] = Input::getInstance().GetKey(PAD_INPUT_1);
		pushKey[2] = Input::getInstance().GetKey(PAD_INPUT_2);
		pushKey[3] = Input::getInstance().GetKey(PAD_INPUT_3);
		pushKey[4] = Input::getInstance().GetKey(PAD_INPUT_4);
		pushKey[5] = Input::getInstance().GetKey(PAD_INPUT_5);
		pushKey[6] = Input::getInstance().GetKey(PAD_INPUT_6);
		pushKey[7] = Input::getInstance().GetKey(PAD_INPUT_7);
		pushKey[8] = Input::getInstance().GetKey(PAD_INPUT_8);
		pushKey[9] = Input::getInstance().GetKey(PAD_INPUT_9);
		pushKey[10] = Input::getInstance().GetKey(PAD_INPUT_10);

		pushUp = Input::getInstance().GetKey(PAD_INPUT_UP);
		pushDown = Input::getInstance().GetKey(PAD_INPUT_DOWN);
		pushRight = Input::getInstance().GetKey(PAD_INPUT_RIGHT);
		pushLeft = Input::getInstance().GetKey(PAD_INPUT_LEFT);
	}
	else {
		
		pushKey[1] = Input::getInstance().GetKey(KEY_INPUT_1);
		pushKey[2] = Input::getInstance().GetKey(KEY_INPUT_2);
		pushKey[3] = Input::getInstance().GetKey(KEY_INPUT_3);
		pushKey[4] = Input::getInstance().GetKey(KEY_INPUT_4);
		pushKey[5] = Input::getInstance().GetKey(KEY_INPUT_5);
		pushKey[6] = Input::getInstance().GetKey(KEY_INPUT_6);
		pushKey[7] = Input::getInstance().GetKey(KEY_INPUT_7);
		pushKey[8] = Input::getInstance().GetKey(KEY_INPUT_8);
		pushKey[9] = Input::getInstance().GetKey(KEY_INPUT_9);
		pushKey[10] = Input::getInstance().GetKey(KEY_INPUT_0);

		pushUp = Input::getInstance().GetKey(KEY_INPUT_UP);
		pushDown = Input::getInstance().GetKey(KEY_INPUT_DOWN);
		pushRight = Input::getInstance().GetKey(KEY_INPUT_RIGHT);
		pushLeft = Input::getInstance().GetKey(KEY_INPUT_LEFT);
	}

}