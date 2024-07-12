#include "GameObject.h"
#include "DxLib.h"

//コンストラクタ
GameObject::GameObject() : image(NULL), location(0.0f), box_size(0.0f),flip_flag(FALSE)
{

}

//デストラクタ
GameObject::~GameObject()
{

}

//初期化処理
void GameObject::Initialize()
{
	image = NULL;

	box_size = Vector2D(32.0f);

	location = box_size;
}

//更新処理
void GameObject::Update()
{
	
}

//描画処理
void GameObject::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, image, TRUE, flip_flag);

	Vector2D upper_left = location - (box_size / 2.0f);
	Vector2D lower_right = location + (box_size / 2.0f);

	DrawBoxAA(upper_left.x, upper_left.y, lower_right.x, lower_right.y, GetColor(255, 0, 0), FALSE);
}

//終了処理
void GameObject::Finalize()
{

}

//locationのセッター
void GameObject::SetLocation(Vector2D location)
{
	this->location = location;
}

//locationのゲッター
Vector2D GameObject::GetLocation() const
{
	return this->location;
}

//GetBoxSizeのゲッター
Vector2D GameObject::GetBoxSize() const
{
	return this->box_size;
}