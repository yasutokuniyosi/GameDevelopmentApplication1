#pragma once

#include "../GameObject.h"

//�v���C���[�p�N���X
class Enemy : public GameObject
{
private:
	int animation[5];         //�A�j���[�V�����摜��ǂݍ��ނ��
	int animation_count;      //�A�j���[�V�����J�E���g
	int animation_image;      //�A�j���[�V�����摜
	int flip_flag;            //�U������t���O 
	int Enemy_Born;           //Enemy����
	int Speed;                //���x

public:
	Enemy();            //�R���X�g���N�^
	virtual ~Enemy();   //�f�X�g���N�^

	virtual void Initialize()override;  //����������
	virtual void Update()override;      //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;    //�I������
	virtual void OnHitCollision(GameObject* hit_object)override;  //�����������̏���

private:
	void Movement();            //�ړ�����
	void AnimationControl();    //�A�j���[�V��������
};