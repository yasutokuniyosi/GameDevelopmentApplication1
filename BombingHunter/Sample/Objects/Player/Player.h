#pragma once

#include "../GameObject.h"

//�v���C���[�p�N���X
class Player : public GameObject
{
private:
	int animation[2];
	int animation_count;
	int flip_flag;

public:
	Player();            //�R���X�g���N�^
	virtual ~Player();   //�f�X�g���N�^

	virtual void Initialize()override;  //����������
	virtual void Update()override;      //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;    //�I������
	virtual void OnHitCollision(GameObject* hit_object)override;

private:
	void Movement();            //�ړ�����
	void AnimationControl();
};