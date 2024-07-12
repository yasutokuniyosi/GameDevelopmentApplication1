#include "GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() : image(NULL), location(0.0f), box_size(0.0f),flip_flag(FALSE)
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{
	image = NULL;

	box_size = Vector2D(32.0f);

	location = box_size;
}

//�X�V����
void GameObject::Update()
{
	
}

//�`�揈��
void GameObject::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE, flip_flag);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255, 0, 0), FALSE);
}

//�I������
void GameObject::Finalize()
{

}

//location�̃Z�b�^�[
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

//location�̃Q�b�^�[
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//GetBoxSize�̃Q�b�^�[
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}