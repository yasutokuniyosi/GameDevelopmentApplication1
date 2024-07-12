#include "Vector2D.h"
#include <math.h>

//�R���X�g���N�^
Vector2D::Vector2D() : x(0.0f), y(0.0f)
{
}

//�R���X�g���N�^
Vector2D::Vector2D(float scalar) : x(scalar), y(scalar)
{
}

//�R���X�g���N�^
Vector2D::Vector2D(float mx, float my) : x(mx), y(my)
{
}

//�f�X�g���N�^
Vector2D::~Vector2D()
{
}

//����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator=(const Vector2D& location)
{
	this->x = location.x;
	this->y = location.y;

	return *this;
}

//���Z:���Z�q�I�[�o�[���[�h
const Vector2D Vector2D::operator+(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x + location.x;
	result.y = this->y + location.y;

	return result;
}

//���Z����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator+=(const Vector2D& location)
{
	this->x += location.x;
	this->y += location.y;

	return *this;
}

//���Z:���Z�q�I�[�o�[���[�h
const Vector2D Vector2D::operator-(const Vector2D& location) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x - location.x;
	result.y = this->y - location.y;

	return result;
}

//���Z����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator-=(const Vector2D& location)
{
	this->x -= location.x;
	this->y -= location.y;

	return *this;
}

//��Z�F���Z�q�I�[�o�[���[�h
const Vector2D Vector2D::operator*(const float& scalar) const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}

//��Z�F���Z�q�I�[�o�[���[�h
const Vector2D Vector2D::operator*(const Vector2D& location)const
{
	Vector2D result = Vector2D(0.0f);

	result.x = this->x * location.x;
	result.y = this->y * location.y;

	return result;
}

//��Z����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator*=(const float& scalar)
{
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}

//��Z����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator*=(const Vector2D& location)
{
	this->x *= location.x;
	this->y *= location.y;

	return *this;
}

//���Z�F���Z�q�I�[�o�[���[
const Vector2D Vector2D::operator/(const float& scalar) const
{
	if (fabsf(scalar) < 1e-6f)
	{
		return Vector2D(0.0f);
	}

	return Vector2D(this->x / scalar, this->y / scalar);
}

//���Z�F���Z�q�I�[�o�[���[
const Vector2D Vector2D::operator/(const Vector2D& location)const
{
	if ((fabsf(location.x) < 1e-6f) || (fabsf(location.y) < 1e-6f))
	{
		return Vector2D(0.0f);
	}

	return Vector2D(this->x / location.x, this->y / location.y);
}

//���Z����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator/=(const float& scalar)
{
	if (fabsf(scalar) < 1e-6f)
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= scalar;
		this->y /= scalar;
	}

	return *this;
}

//���Z����F���Z�q�I�[�o�[���[�h
Vector2D& Vector2D::operator/=(const Vector2D& location)
{
	if ((fabsf(location.x) < 1e-6f) || (fabsf(location.y) < 1e-6f))
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= location.x;
		this->y /= location.y;
	}

	return *this;
}

//�����^�f�[�^�ɕϊ�
void Vector2D::ToInt(int* x, int* y)const
{
	*x = static_cast<int>(this->x);
	*y = static_cast<int>(this->y);
}