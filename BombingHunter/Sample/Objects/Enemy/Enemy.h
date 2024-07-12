#pragma once

#include "../GameObject.h"

//�v���C���[�p�N���X
class Enemy : public GameObject
{
private:
	int animation[2];       //�A�j���[�V��������
	int animation_count;    //�A�j���[�V��������
	Vector2D direction;     //�i�s����

public:
	Enemy();            //�R���X�g���N�^
    ~Enemy();           //�f�X�g���N�^

	virtual void Initialize()override;  //����������
	virtual void Update()override;      //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;    //�I������
	virtual void OnHitCollision(GameObject* hit_object)override;//�����蔻��ʒm����

private:
	void Movement();            //�ړ�����
	void AnimationControl();    //�A�j���[�V��������
};