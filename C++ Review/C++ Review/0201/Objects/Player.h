#pragma once

#include "../Utility/Vector2D.h"

//プレイヤー用クラス
class Player
{
private:
	Vector2D location;   //位置
	Vector2D direction;  //方向
	float radius;        //半径

public:
	Player();                   //コンストラクタ
	Player(float x, float y);   //コンストラクタ
	Player(Vector2D location);  //コンストラクタ
	~Player();                  //ディストラクタ

	void Update();       //更新処理
	void Draw() const;   //描画処理

	void SetLocation(float x, float y);   //locationのセッター
	void SetLocation(Vector2D location);  //locationのセッター
	Vector2D GetLocation() const;         //locationのゲッター
	float GetRadius();                    //Radiusのゲッター

private:
	void Movement();                      //移動処理
};