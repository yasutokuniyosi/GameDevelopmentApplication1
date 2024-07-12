#pragma once

#include "../GameObject.h"

//�v���C���[�p�N���X
class Bom : public GameObject
{
private:
	int animation[4];      //�A�j���[�V�����摜��ǂݍ��ނ��
	int animation_count;   //�A�j���[�V�����J�E���g
	int animation_image;   //�A�j���[�V�����摜
	int flip_flag;         //�U������t���O 
	int Bom_Born;          //Bom����
	int x;                 //�N���X�C�b�`
	Vector2D velocity;     //�ړ����x

public:
	Bom();            //�R���X�g���N�^
	virtual ~Bom();   //�f�X�g���N�^

	virtual void Initialize()override;  //����������
	virtual void Update()override;      //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;    //�I������
	virtual void OnHitCollision(GameObject* hit_object)override;

private:
	void Movement();            //�ړ�����
	void AnimationControl();    //�A�j���[�V��������
};