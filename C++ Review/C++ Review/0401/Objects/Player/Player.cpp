#include "Player.h"
#include "../../Utility/InputControl.h"
#include "../../Utility/UserTemplate.h"
#include "../../Utility/ResourceManager.h"
#include "DxLib.h"

//	�R���X�g���N�^
Player::Player() :
	velocity(0.0f),
	animation_data(),
	animation_count(0)
{

}

//�f�X�g���N�^
Player::~Player()
{

}

//����������
void Player::Initialize()
{
	box_size = Vector2D(32.0f);
	location = Vector2D(320.0f, 240.0f);

	ResourceManager* rm = ResourceManager::GetInstance();
	std::vector<int> tmp;
	tmp = rm->GetImages("0401/Resource/Images/Tri-pilot/1.png");
	animation_data.push_back(tmp[0]);
	tmp = rm->GetImages("0401/Resource/Images/Tri-pilot/2.png");
	animation_data.push_back(tmp[0]);

	image = animation_data[0];

	animation_count = 0;
}

//�X�V����
void Player::Update()
{
	Movement();

	AnimationControl();
}

//�`�揈��
void Player::Draw() const
{
	__super::Draw();
}

//�I������
void Player::Finalize()
{
	animation_data.clear();
}

//�ړ�����
void Player::Movement()
{
	//���͏��̎擾
	InputControl* input = InputControl::GetInstance();

	float direction = 0.0f;
	if (input->GetKey(KEY_INPUT_LEFT))
	{
		//���ړ�
		//�ړ���������
		direction = -1.0f;
		flip_flag = TRUE;
	}
	else if (input->GetKey(KEY_INPUT_RIGHT))
	{
		//�E�ړ�
		//�ړ���������
		direction = 1.0f;
		flip_flag = FALSE;
	}

	if (direction != 0.0f)
	{
		float max_speed = Abs<float>((5.0f * 0.5f * direction));
		velocity.x += 0.5f * direction;
		velocity.x = Min<float>(Max<float>(velocity.x, -max_speed), max_speed);
	}
	else
	{
		//���͂Ȃ�
		//��������
		if (velocity.x < -1e-6f)
		{
			//�E�ړ��̌���
			float calc_speed = velocity.x + 0.1f;
			velocity.x = Min<float>(calc_speed, 0.0f);
		}
		else if (-1e-6f < velocity.x)
		{
			//���ړ��̌���
			float calc_speed = velocity.x - 0.1f;
			velocity.x = Max<float>(calc_speed, 0.0f);
		}
	}

	//�ǂ̏Փ˃`�F�b�N
	if (location.x < (box_size.x / 2.0f))
	{
		//����
		velocity.x = 0.0f;
		location.x = box_size.x / 2.0f;
	}
	else if (location.x > (640.0f - box_size.x / 2.0f))
	{
		//�E��
		velocity.x = 0.0f;
		location.x = 640.0f - box_size.x / 2.0f;
	}

	//���W�ړ�
	location += velocity;
}

//�A�j���[�V��������
void Player::AnimationControl()
{
	animation_count++;

	if (animation_count >= 30)
	{
		animation_count = 0;

		if (image == animation_data[0])
		{
			image = animation_data[1];
		}
		else
		{
			image = animation_data[0];
		}
	}
}