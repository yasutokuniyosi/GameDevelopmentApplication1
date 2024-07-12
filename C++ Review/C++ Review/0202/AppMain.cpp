#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"

//���C���֐��i�v���O�����͂�������n�܂�܂��B�j
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	ChangeWindowMode(TRUE);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{
		return -1;  //���������s
	}

	//�`���𗠉�ʂɐݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[���I�u�W�F�N�g�̐���
	GameObject* object1 = new GameObject();

	//�v���C���[�̐���
	Player* object2 = new Player();

	//�I�u�W�F�N�g�̏���������
	object1->Initialize();

	//�v���C���[�̐���
	object2->Initialize();

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();  //�L�[�{�[�h���͊Ǘ��@�\�̍X�V����

		object1->Update();       //�Q�[���I�u�W�F�N�g�̍X�V����
		object2->Update();       //�v���C���[�̍X�V����

		ClearDrawScreen();       //��ʂ̍폜

		object1->Draw();         //�Q�[���I�u�W�F�N�g�̕`�揈��
		object2->Draw();         //�v���C���[�̕`�揈��

		ScreenFlip();            //��ʂ̍X�V

	}

	delete object1;     //�Q�[���I�u�W�F�N�g�̍폜
	delete object2;     //�v���C���[�̍폜

	DxLib_End();   //Dx���C�u�����̏I������

	return 0;//����I����ʒm
}