#pragma once

#include "../GameObject.h"

//プレイヤー用クラス
class Player : public GameObject
{
private:
	Vector2D velocity;

public:
	Player();            //コンストラクタ
	virtual ~Player();   //デストラクタ

	virtual void Initialize();  //初期化処理
	virtual void Update();      //更新処理
	virtual void Draw() const;  //描画処理
	virtual void Finalize();    //終了処理

private:
	void Movement();            //移動処理
};