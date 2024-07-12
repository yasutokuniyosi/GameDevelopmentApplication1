#include "DxLib.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputControl.h"
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

	//�v���C���[�𐶐�����
	GameObject* object = new Player();
	ResourceManager* resource_manager = GetResourceManager();

	//�`���𗠉�ʂɐݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	try
	{
		object->Initialize();

		//�Q�[�����C�����[�v
		while (ProcessMessage() != -1)
		{
			InputControl::Update();  //�L�[�{�[�h���͊Ǘ��@�\�̍X�V����

	        object->Update(); //�I�u�W�F�N�g�̍X�V����

			ClearDrawScreen();       //��ʂ̍폜

			object->Draw();          //�I�u�W�F�N�g�̕`�揈��

			ScreenFlip();            //��ʂ̍X�V

			if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}

	//�G���[�̃��O���f�o�b�N�̊O�ɏ���
	catch (std::string error_log)
	{
		OutputDebugString(error_log.c_str());
	}

	object->Finalize();//�I�u�W�F�N�g�̏I������

	delete object;//�I�u�W�F�N�g�̍폜

	resource_manager->DeleteImages();//���\�[�X�̍폜����

	DxLib_End();   //Dx���C�u�����̏I������

	return 0;//����I����ʒm
}