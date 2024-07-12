#include "Bom.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"


//	�R���X�g���N�^
Bom::Bom() : animation_count(0), flip_flag(FALSE), animation_image(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	Bom_Born = 1;
	x = 0;
}

//�f�X�g���N�^
Bom::~Bom()
{
}

//����������
void Bom::Initialize()
{
		//�摜�̓ǂݍ���
		animation[0] = LoadGraph("Resource/Images/Bom.png");
		animation[1] = LoadGraph("Resource/Images/2 (4).png");
		animation[2] = LoadGraph("Resource/Images/3 (1).png");
		animation[3] = LoadGraph("Resource/Images/1 (4).png");
	
	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("���e�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 90*(3.14/180);

	//�����蔻��̑傫����ݒ�
	box_size = (64.0f);

	//�������摜�̐ݒ�
	image = animation[animation_image];

	//���ʔԍ���3
	w = 3;

	//�����͂Q
	velocity.y = 2.0f;

	//�N���X�C�b�`�͂O
	x = 0;
}

//�X�V����
void Bom::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Bom::Draw() const
{

	//���e�̉摜�̕`��
	DrawRotaGraphF(location.x, location.y, 0.7, radian , image, TRUE, flip_flag);

//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//�I������
void Bom::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//�����蔻��ʒm����
void Bom::OnHitCollision(GameObject* hit_object)
{
	//���ʔԍ�2�i�G�j�������������̏���
	if (hit_object->read() == 2)
	{
		//�N���X�C�b�`��1�ɂ��Ĕ��e�̗������~�߂�
		x = 1;
		velocity.y = 0.0f;
	}
}


//�ړ�����
void Bom::Movement()
{
	//�ړ����x�ɉ����Ĕ��e�̏ꏊ��ς���
	location += velocity;
	if (location.y >= 400)
	{
	    //�N���X�C�b�`��1�ɂ��Ĕ��e�̗������~�߂�
		x = 1;
		velocity.y = 0.0f;
	}
}

//�A�j���[�V��������
void Bom::AnimationControl()
{
		//�A�j���[�V�����J�E���g�����Z����
		animation_count++;
			
		//�N���X�C�b�`���P�ɂȂ����甚���̃A�j���[�V�����ɕς���
		if (x == 1)
		{
			//20�t���[���ڂɓ��B������
			if (animation_count >= 20)
			{
				//�J�E���g�̃��Z�b�g
				animation_count = 0;
				animation_image++;

				//�摜�̐ؑ�
				if (animation[animation_image] == NULL)
				{
					image = animation[0];
					animation_image = 0;
					//�����̃A�j���[�V�������I�������A�f���[�g�t���O��TRUE�ɂ���
					Delete_flag = TRUE;
					
				}
				else
				{
					radian = 0;
					image = animation[animation_image];
				}
			}
		}


		//if (image == animation[0])
		//{
			//image = animation[1];
		//}
		//else
		//{
			//image = animation[0];
		//}
}