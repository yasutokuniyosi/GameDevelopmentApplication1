#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//	�R���X�g���N�^
Player::Player() : animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//�f�X�g���N�^
Player::~Player()
{
}

//����������
void Player::Initialize()
{
	//�摜�̓ǂݍ���
	animation[0] = LoadGraph("Resource/images/Tripilot1.png");
	animation[1] = LoadGraph("Resource/images/Tripilot2.png");

	//�G���[�`�F�b�N
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("���p�C���b�g�̉摜������܂���\n");
	}

	//�����̐ݒ�
	radian = 0.0f;

	//�����蔻��̑傫����ݒ�
	box_size = (64.0f);
		
	//�������摜�̐ݒ�
	image = animation[0];

	//���ʔԍ��͂P
	w = 1;
}

//�X�V����
void Player::Update()
{
	//�ړ�����
	Movement();
	//�A�j���[�V��������
	AnimationControl();
}

//�`�揈��
void Player::Draw() const
{
	//�v���C���[�摜�̕`��
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

//�f�o�b�O�p
#if _DEBUG
	//�����蔻��̉���
	Vector2D ul = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//�I������
void Player::Finalize()
{
	//�g�p�����摜�����
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//�����蔻��ʒm����
void Player::OnHitCollision(GameObject* hit_object)
{
	//�����������̏���
}


//�ړ�����
void Player::Movement()
{
	Vector2D velocity = 0.0f;

	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		//���ړ�
		//�ړ���������
		velocity.x += -1.0f;
		flip_flag = TRUE;
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		//�E�ړ�
		//�ړ���������
		velocity.x += 1.0f;
		flip_flag = FALSE;
	}
	else
	{
		velocity.x = 0.0f;
	}

	//���݂̈ʒu���W�ɑ��������Z����
	location += velocity;
}

//�A�j���[�V��������
void Player::AnimationControl()
{
	//�A�j���[�V�����J�E���g�����Z����
	animation_count++;

	//60�t���[���ڂɓ��B������
	if (animation_count >= 60)
	{
		//�J�E���g�̃��Z�b�g
		animation_count = 0;

		//�摜�̐ؑ�
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}