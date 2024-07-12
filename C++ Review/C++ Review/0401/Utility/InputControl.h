#pragma once

#define D_KEYCODE_MAX (256) //�L�[�R�[�h�̑���

//�L�[�{�[�h���͊Ǘ��@�\		
class InputControl
{
private:
	static InputControl* instance;

	char now_key[D_KEYCODE_MAX];//���݃t���[�����͒l
    char old_key[D_KEYCODE_MAX];//�ߋ��t���[�����͒l

private:
	InputControl() = default;

	InputControl(InputControl& v) = delete;
	InputControl& operator = (const InputControl& v) = delete;

public:
	~InputControl() = default;

public:
	static InputControl* GetInstance();
	static void DeleteInstance();
public:
	void Update();                 //�X�V����

	bool GetKey(int key_code)const;     //���������Ă����
	bool GetKeyDown(int key_code)const; //�������u��
    bool GetKeyUp(int key_code) const;	  //�������u��

private:
	//�L�[�z��͈̓`�F�b�N
	bool CheckKeyCodeRange(int key_code) const;
};