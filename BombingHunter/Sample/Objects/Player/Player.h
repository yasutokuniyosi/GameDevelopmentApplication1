#pragma once

#include "../GameObject.h"

//プレイヤー用クラス
class Player : public GameObject
{
private:
	int animation[2];
	int animation_count;
	int flip_flag;

public:
	Player();            //コンストラクタ
	virtual ~Player();   //デストラクタ

	virtual void Initialize()override;  //初期化処理
	virtual void Update()override;      //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;    //終了処理
	virtual void OnHitCollision(GameObject* hit_object)override;

private:
	void Movement();            //移動処理
	void AnimationControl();
};