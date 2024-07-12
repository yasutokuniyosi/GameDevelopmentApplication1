#include "Player.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

//コンストラクタ
Player::Player() :location(), direction(0.0f), radius(15.0f)
{
}

//コンストラクタ
Player::Player(float x,float y) :location(x,y), direction(0.0f), radius(15.0f)
{
}

//コンストラクタ
Player::Player(Vector2D Location) : direction(0.0f), radius(15.0f)
{
	this->location = location;
}
	
//ディストラクタ
Player::~Player()
{

}

//更新処理
void Player::Update()
{
	Movement();
}

//描画処理
void Player::Draw() const
{
	DrawCircleAA(location.x, location.y, radius, 50, GetColor(255, 255, 255), TRUE);
}

//locationのセッター
void Player::SetLocation(float x,float y)
{
	SetLocation(Vector2D(x, y));
}

//locationのセッター
void Player::SetLocation(Vector2D location)
{
	this->location = location;
}

//locationのゲッター
Vector2D Player::GetLocation() const
{
	return location;
}

//Radiusのゲッター
float Player::GetRadius()
{
	return radius;
}

//移動処理
void Player::Movement()
{
	//上
	if (InputControl::GetKeyDown(KEY_INPUT_UP))
	{
		direction.y = -1.0f;
	}

	//下
	if (InputControl::GetKeyDown(KEY_INPUT_DOWN))
	{
		direction.y = 1.0f;
	}

	//左
	if (InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		direction.x = 1.0f;
	}

	//右
	if (InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		direction.x = -1.0f;
	}

	//座標移動
	location += direction;
}