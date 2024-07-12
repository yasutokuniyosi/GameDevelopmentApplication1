#pragma once

#include "../GameObject.h"

//プレイヤー用クラス
class Enemy : public GameObject
{
private:
	int animation[5];         //アニメーション画像を読み込むやつ
	int animation_count;      //アニメーションカウント
	int animation_image;      //アニメーション画像
	int flip_flag;            //振り向きフラグ 
	int Enemy_Born;           //Enemy生成
	int Speed;                //速度

public:
	Enemy();            //コンストラクタ
	virtual ~Enemy();   //デストラクタ

	virtual void Initialize()override;  //初期化処理
	virtual void Update()override;      //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;    //終了処理
	virtual void OnHitCollision(GameObject* hit_object)override;  //当たった時の処理

private:
	void Movement();            //移動処理
	void AnimationControl();    //アニメーション制御
};