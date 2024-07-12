#pragma once

#include "../GameObject.h"

//プレイヤー用クラス
class Enemy : public GameObject
{
private:
	int animation[2];       //アニメーション制御
	int animation_count;    //アニメーション時間
	Vector2D direction;     //進行方向

public:
	Enemy();            //コンストラクタ
    ~Enemy();           //デストラクタ

	virtual void Initialize()override;  //初期化処理
	virtual void Update()override;      //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;    //終了処理
	virtual void OnHitCollision(GameObject* hit_object)override;//当たり判定通知処理

private:
	void Movement();            //移動処理
	void AnimationControl();    //アニメーション制御
};