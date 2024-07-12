#include "DxLib.h"
#include "Utility/InputControl.h"
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

	//�v���C���[�𐶐�����
	Player* player = new Player();

	//�`���𗠉�ʂɐݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		//���͏��
		InputControl::Update();

		//�v���C���[�̍X�V����
		player->Update();

		
		//�ǂɐG�ꂽ�甽�Α��̕ǂɈړ����鏈��
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;          //���̕ǂ���E�̕ǂ�
			}
			else
			{
				tmp.x = 0.0f;            //�E�̕ǂ��獶�̕ǂ�
			}
			player->SetLocation(tmp);
		}

		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;          //��̕ǂ��牺�̕ǂ�
			}
			else
			{
				tmp.y = 0.0f;            //���̕ǂ����̕ǂ�
			}
		}
		player->SetLocation(tmp);//���W�̍X�V

		ClearDrawScreen();  //��ʂ̍폜

		player->Draw();     //�`�揈��

		ScreenFlip();       //��ʂ̍X�V

		//�I���{�^������
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	delete player;//�v���C���[�̃f�[�^�폜

	DxLib_End();//DX���C�u�����̏I������

	//����I����ʒm
	return 0;
}