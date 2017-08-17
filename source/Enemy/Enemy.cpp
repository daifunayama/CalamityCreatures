#include "Enemy.h"
#include "../Parameter.h"
#include "../Utility.h"
#include "DxLib.h"

ss::Quad Enemy::getQuad(const char* name) {
	ss::Quad mQuad = mSprite->getPartQuad(name);
	return mQuad;
}

void Enemy::LoadGraphic() {
	//�v���C���[�̍쐬
	mSprite = ss::Player::create();

	//�v���C���[�Ƀ��\�[�X�����蓖��
	mSprite->setData("E1");// ssbp�t�@�C����

	mSprite->play("E1/idle");// �A�j���[�V���������w��

	 //�\���ʒu��ݒ�
	mSprite->setPosition(400, 500);
	//�X�P�[���ݒ�
	mSprite->setScale(0.3f,0.3f);

	mSprite->setStep(0.3f);
}

void Enemy::Process() {
	mSprite->update((float)30 / 1000);
}

void Enemy::Draw() {
	mSprite->draw();
	ss::ResluteState state;

	int box = LoadGraph("Data/graphic/box.png");
	ss::Quad mQuad = mSprite->getPartQuad("armB2");

	SetDrawBlendMode(DX_BLENDMODE_ALPHA_X4, 100);
	DrawModiGraphF(mQuad.tl.x,mQuad.tl.y, mQuad.tr.x, mQuad.tr.y, 
		mQuad.br.x,  mQuad.br.y, mQuad.bl.x,  mQuad.bl.y, box, true);

	DrawCircle(mQuad.tl.x, mQuad.tl.y, 3, Parameter::COLOR_RED, 1, 1);
	DrawCircle(mQuad.tr.x, mQuad.tr.y, 3, Parameter::COLOR_GREEN, 1, 1);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}