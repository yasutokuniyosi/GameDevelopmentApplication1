#pragma once

#include "../Utility/Vector2D.h"

#define D_PIVOT_CENTER  //���W�̌��_�𒆐S�ɂ���

//�Q�[���I�u�W�F�N�g���N���X
class GameObject
{
protected:
	Vector2D location;             //�ʒu���
	Vector2D box_size;             //���̑傫��
	double scale;                  //�傫��
	double radian;                 //����
	int image;                     //�`�悷��摜
	int sound;                     //�Đ����鉹��
	int Delete_flag;               //��������t���O
	int w;                         //���ʂ�����
	int Score_flag;                //�X�R�A�̃t���O

public:
	GameObject();
	virtual ~GameObject();

	virtual void Initialize();     //����������
	virtual void Update();            //�X�V����
	virtual void Draw() const;     //�`�揈��
	virtual void Finalize();       //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object);

	//�ʒu���擾����
	Vector2D GetLocation() const;
	//�ʒu���ύX����
	void SetLocation(const Vector2D& location);

	//�����蔻��̑傫�����擾����
	Vector2D GetBoxSize() const;

	//��������t���O��Scene�ɑ���
	int GetDelete_flag();

	//w���e�I�u�W�F�N�g�ɑ���
	int read();

	//��ɓ��ꂽ�X�R�A��Scene�ɑ���B
	int GetScore();
};