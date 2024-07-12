#include "GameObject.h"
#include "DxLib.h"

//�R���X�g���N�^
GameObject::GameObject() : color(0x0), location(), box_size()
{

}

//�f�X�g���N�^
GameObject::~GameObject()
{

}

//����������
void GameObject::Initialize()
{
	color = GetColor(255, 0, 0);

	box_size = Vector2D(32.0f);

	location = box_size;
}

//�X�V����
void GameObject::Update()
{
	//�E�����ɐi�ݑ�����	
	location.x += 1.0f;

	//�E�̒[�ɍs���ƁA���̒[�Ɉړ�����
	if (location.x >= 640.0f)
	{
		location.x = 0.0f;
	}
}

//�`�揈��
void GameObject::Draw() const
{
	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, color, TRUE);
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