#include "Enemy.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"


//	�R���X�g���N�^
Enemy::Enemy() : animation_count(0), flip_flag(FALSE),animation_image(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	animation[4] = NULL;
	Enemy_Born = 1;
	Speed = 0;
}

//�f�X�g���N�^
Enemy::~Enemy()
{
}

//����������
void Enemy::Initialize()
{
	//�����_���ɓG��ς���
	int EnemyChange = GetRand(100);

	if (location.x == 100)
	{
		flip_flag = FALSE;
	}
	if(location.x == 540)
	{
		flip_flag = TRUE;
	}

	//�n�R�G
	if (EnemyChange >= 50)
	{
		//�摜�̓ǂݍ���
		animation[0] = LoadGraph("Resource/Images/1 (1).png");
		animation[1] = LoadGraph("Resource/Images/2 (1).png");
		animation[2] = NULL;
		animation[3] = NULL;
		animation[4] = NULL;

		//Y���W�͌Œ�
		location.y = 400.0f;
	}
	//
	else if (EnemyChange < 30)
	{
		//�摜�̓ǂݍ���
		animation[0] = LoadGraph("Resource/Images/1.png");
		animation[1] = LoadGraph("Resource/Images/2.png");
		animation[2] = NULL;
		animation[3] = NULL;
		animation[4] = NULL;
		//���W������������
		location.y -= 50.0f;
	}
	//���A�G
	else if (30<=EnemyChange < 40)
	{
		//�摜�̓ǂݍ���
		animation[0] = LoadGraph("Resource/Images/1 (3).png");
		animation[1] = LoadGraph("Resource/Images/2 (3).png");
		animation[2] = LoadGraph("Resource/Images/3.png");
		animation[3] = LoadGraph("Resource/Images/4.png");
		animation[4] = LoadGraph("Resource/Images/5.png");

		//Y���W�͌Œ�
		location.y = 400.0f;

		//�X�s�[�h���P�l��
		Speed = 1;
	}

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("���G�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = (64.0f);

	//�������摜�̐ݒ�
	image = animation[animation_image];

	//���ʔԍ��͂Q
	w = 2;
}

//�X�V����
void Enemy::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Enemy::Draw() const
{
	
	//�G�̉摜�̕`��
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);
	
//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif

	//�e�N���X�̕`�揈�����Ăяo��
	__super::Draw();
}

//�I������
void Enemy::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
}

//�����蔻��ʒm����
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//���ʔԍ��R�i���e�j�������������̏���
	if (hit_object->read() == 3)
	{
		//�f���[�g�t���O��TRUE�ɂ���
		Delete_flag = TRUE;
	}
}


//�ړ�����
void Enemy::Movement()
{
	Vector2D velocity = 0.0f;
	if (flip_flag == FALSE)
	{
		if (location.x >= 500)
		{

			Delete_flag = TRUE;
		}
		else if (location.x <= 500)
		{
			//�E�ړ�
			//�ړ���������
			//���A�G�͑���2�{
			if (Speed == 1)
			{
				velocity.x = 2.0f;
			}
			else
			{
				velocity.x = 1.0f;
			}
		}
		else
		{
			velocity.x = 0.0f;
		}
	}

	else if (flip_flag == TRUE)
	{
		if (location.x <= 100)
		{

			Delete_flag = TRUE;
		}
		else if (location.x >= 100)
		{
			//���ړ�
			//�ړ���������
			//���A�G�͑���2�{
			if (Speed == 1)
			{
				velocity.x = -2.0f;
			}
			else 
			{
				velocity.x = -1.0f;
			}
		}
		else
		{
			velocity.x = 0.0f;
		}
	}

	

	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Enemy::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;
		animation_image++;

		//�摜�̐ؑ�
		if (animation[animation_image] == NULL)
		{
			image = animation[0];
			animation_image = 0;
		}
		else
		{
			image = animation[animation_image];
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
}