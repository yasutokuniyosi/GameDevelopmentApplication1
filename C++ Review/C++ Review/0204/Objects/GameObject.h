#pragma once

#include "../Utility/Vector2D.h"

//�Q�[���I�u�W�F�N�g�N���X
class GameObject
{
protected:
	int image;    //�F
	Vector2D location;     //�ʒu
	Vector2D box_size;     //���̑傫��

public:
	GameObject();          //�R���X�g���N�^
	virtual ~GameObject(); //�f�X�g���N�^

	virtual void Initialize();//����������
	virtual void Update();    //�X�V����
	virtual void Draw() const;//�`�揈��
	virtual void Finalize();  //�I������

public:
	void SetLocation(Vector2D location);//location�̃Z�b�^�[
	Vector2D GetLocation() const;//location�̃Q�b�^�[
	Vector2D GetBoxSize() const; //BoxSize�̃Q�b�^�[
};