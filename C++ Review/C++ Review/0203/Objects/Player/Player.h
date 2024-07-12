#pragma once

#include "../GameObject.h"

//�v���C���[�p�N���X
class Player : public GameObject
{
private:
	Vector2D velocity;

public:
	Player();            //�R���X�g���N�^
	virtual ~Player();   //�f�X�g���N�^

	virtual void Initialize();  //����������
	virtual void Update();      //�X�V����
	virtual void Draw() const;  //�`�揈��
	virtual void Finalize();    //�I������

private:
	void Movement();            //�ړ�����
};