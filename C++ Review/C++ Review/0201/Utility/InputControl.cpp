#include "InputControl.h"
#include "DxLib.h"

//�ÓI�����o�ϐ���`
char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};

//���͋@�\ : �X�V����
void InputControl::Update()
{
	//�O�t���[���̓��͏��Ɍ��݂̓��͏����R�s�[����
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//���݂̓��͏����X�V����
	GetHitKeyStateAll(now_key);
}

//�L�[�擾:�����Ă����
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}

//�L�[�擾:�������u��
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}

//�L�[�擾:�������u�ԏu��
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}

//�L�[�z��͈̓`�F�b�N
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}