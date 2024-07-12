#pragma once

#include "../Utility/Vector2D.h"

//�v���C���[�p�N���X
class Player
{
private:
	Vector2D location;   //�ʒu
	Vector2D direction;  //����
	float radius;        //���a

public:
	Player();                   //�R���X�g���N�^
	Player(float x, float y);   //�R���X�g���N�^
	Player(Vector2D location);  //�R���X�g���N�^
	~Player();                  //�f�B�X�g���N�^

	void Update();       //�X�V����
	void Draw() const;   //�`�揈��

	void SetLocation(float x, float y);   //location�̃Z�b�^�[
	void SetLocation(Vector2D location);  //location�̃Z�b�^�[
	Vector2D GetLocation() const;         //location�̃Q�b�^�[
	float GetRadius();                    //Radius�̃Q�b�^�[

private:
	void Movement();                      //�ړ�����
};