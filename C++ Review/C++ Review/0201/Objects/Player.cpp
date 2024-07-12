#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

//�R���X�g���N�^
Player::Player() :location(), direction(0.0f), radius(15.0f)
{
}

//�R���X�g���N�^
Player::Player(float x,float y) :location(x,y), direction(0.0f), radius(15.0f)
{
}

//�R���X�g���N�^
Player::Player(Vector2D Location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}
	
//�f�B�X�g���N�^
Player::~Player()
{

}

//�X�V����
void Player::Update()
{
	Movement();
}

//�`�揈��
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);
}

//location�̃Z�b�^�[
void Player::SetLocation(float x,float y)
{
	SetLocation(Vector2D(x, y));
}

//location�̃Z�b�^�[
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}

//location�̃Q�b�^�[
Vector2D Player::GetLocation() const
{
	return location;
}

//Radius�̃Q�b�^�[
float Player::GetRadius()
{
	return radius;
}

//�ړ�����
void Player::Movement()
{
	//��
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}

	//��
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 1.0f;
	}

	//��
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 1.0f;
	}

	//�E
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;
	}

	//���W�ړ�
	location += direction;
}