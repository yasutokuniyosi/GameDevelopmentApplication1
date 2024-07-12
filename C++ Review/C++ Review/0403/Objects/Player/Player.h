#pragma once

#include "../GameObject.h"
#include <vector>

//�v���C���[�p�N���X
class Player : public GameObject
{
private:
	Vector2D velocity;
	std::vector<int>animation_data;
	int animation_count;

public:
	Player();            //�R���X�g���N�^
	virtual ~Player();   //�f�X�g���N�^

	virtual void Initialize()override;  //����������
	virtual void Update()override;      //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize()override;    //�I������

private:
	void Movement();            //�ړ�����
	void AnimationControl();    //�A�j���[�V��������
};