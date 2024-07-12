#pragma once

#define D_KEYCODE_MAX (256) //�L�[�R�[�h�̑���

//�L�[�{�[�h���͊Ǘ��@�\		
class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];//���݃t���[�����͒l
	static char old_key[D_KEYCODE_MAX];//�ߋ��t���[�����͒l

public:
	static void Update();                 //�X�V����

	static bool GetKey(int key_code);     //���������Ă����
	static bool GetKeyDown(int key_code); //�������u��
	static bool GetKeyUp(int key_code);	  //�������u��

private:
	//�L�[�z��͈̓`�F�b�N
	static bool CheckKeyCodeRange(int key_code);
};