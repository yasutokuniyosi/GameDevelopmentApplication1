#pragma once

//2�����x�N�g���N���X
class Vector2D
{
public:
	float x;   //x����
	float y;   //y����

public:
	Vector2D();                    //�R���X�g���N�^
	Vector2D(float scalar);        //�R���X�g���N�^
	Vector2D(float mx, float my);  //�R���X�g���N�^
	~Vector2D();                   //�f�B�X�g���N�^

public:
	//���Z�q�I�[�o�[���[�h���g���Ă���
	Vector2D& operator = (const Vector2D& location);   //����F���Z�q�I�[�o�[���[�h

	const Vector2D operator + (const Vector2D& location) const;    //���Z:���Z�q�I�[�o�[���[�h
	Vector2D& operator +=  (const Vector2D& location);             //���Z����F���Z�q�I�[�o�[���[�h

	const Vector2D operator - (const Vector2D& location) const;    //���Z:���Z�q�I�[�o�[���[�h
	Vector2D& operator -=  (const Vector2D& location);             //���Z����F���Z�q�I�[�o�[���[�h

	const Vector2D operator * (const float& scalar) const;         //��Z�F���Z�q�I�[�o�[���[�h
	const Vector2D operator * (const Vector2D& location) const;    //��Z�F���Z�q�I�[�o�[���[�h
	Vector2D& operator *=  (const float& scalar);                  //��Z����F���Z�q�I�[�o�[���[�h
	Vector2D& operator *=  (const Vector2D& location);             //��Z����F���Z�q�I�[�o�[���[�h

	const Vector2D operator / (const float& scalar) const;         //���Z�F���Z�q�I�[�o�[���[�h
	const Vector2D operator / (const Vector2D& location) const;    //���Z�F���Z�q�I�[�o�[���[�h
	Vector2D& operator /=  (const float& scalar);                  //���Z����F���Z�q�I�[�o�[���[�h
	Vector2D& operator /=  (const Vector2D& location);             //���Z����F���Z�q�I�[�o�[���[�h

	/*
	*�����^�f�[�^�ɕϊ�
	*�����F
	* �@x��y�����𐮐��^�ɕϊ����A
	*����
	*	 int* x x�������󂯎��ϐ�
	*	 int* y y�������󂯎��ϐ�
	*/
	void ToInt(int* x, int* y) const;
};