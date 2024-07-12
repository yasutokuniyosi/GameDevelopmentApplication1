#pragma once

#define D_KEYCODE_MAX (256)   //�L�[���͍ő�l

//���͐���N���X�i�����o�͐ÓI�N���X�ŏ��L����j
class InputControl
{
//��{�I�Ƀ����o�ϐ��̓v���C�x�[�g
private:
	static char now_key[D_KEYCODE_MAX];    //���݂̓��͒l
	static char old_key[D_KEYCODE_MAX];    //�O��̓��͒l

//�֐��̓p�u���b�N
public:
	static void Update();                 //�X�V����

	static bool GetKey(int key_code);      //���������Ă��邩�H
	static bool GetKeyDown(int key_code);  //�������u�Ԃ��H
	static bool GetKeyUp(int key_code);    //�������u�Ԃ��H

//�O�����J�̕K�v���Ȃ���΁A�v���C�x�[�g
private:
	static bool CheckKeyCodeRange(int key_code);   //�L�[�R�[�h�͈̓`�F�b�N
};