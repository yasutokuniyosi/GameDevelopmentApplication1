#pragma once

#include "GameObject.h"

//�v���C���[�p�N���X
class Player : public GameObject
{
private:

public:
	Player();            //�R���X�g���N�^
	~Player()override;   //�f�X�g���N�^

    void Initialize() override;  //����������
    void Update() override;      //�X�V����
	void Draw() const override;  //�`�揈��
	void Finalize() override;    //�I������

private:
	void Movement();            //�ړ�����
};