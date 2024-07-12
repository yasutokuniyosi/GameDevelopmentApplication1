#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player/Player.h"

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

	GameObject* objects[2] = { nullptr,nullptr };
	objects[0] = new GameObject();   //�����œ����I�u�W�F�N�g
	objects[1] = new Player();       //���삷��I�u�W�F�N�g

	//�I�u�W�F�N�g�̏���������
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize(); 
	}

	//�`���𗠉�ʂɐݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();  //�L�[�{�[�h���͊Ǘ��@�\�̍X�V����

		//�I�u�W�F�N�g�̍X�V����
		for (int i = 0; i < 2; i++) 
		{
			objects[i]->Update(); 
		}

		ClearDrawScreen();       //��ʂ̍폜

		//�I�u�W�F�N�g�̕`�揈��
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();  
		}

		ScreenFlip();            //��ʂ̍X�V

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//�I�u�W�F�N�g�̍폜
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i];
	}

	DxLib_End();   //Dx���C�u�����̏I������

	return 0;//����I����ʒm
}