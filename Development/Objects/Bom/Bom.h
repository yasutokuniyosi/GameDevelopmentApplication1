#pragma once

#include "../GameObject.h"

//プレイヤー用クラス
class Bom : public GameObject
{
private:
	int animation[4];      //アニメーション画像を読み込むやつ
	int animation_count;   //アニメーションカウント
	int animation_image;   //アニメーション画像
	int flip_flag;         //振り向きフラグ 
	int Bom_Born;          //Bom生成
	int x;                 //起爆スイッチ
	Vector2D velocity;     //移動速度

public:
	Bom();            //コンストラクタ
	virtual ~Bom();   //デストラクタ

	virtual void Initialize()override;  //初期化処理
	virtual void Update()override;      //更新処理
	virtual void Draw() const override;  //描画処理
	virtual void Finalize() override;    //終了処理
	virtual void OnHitCollision(GameObject* hit_object)override;

private:
	void Movement();            //移動処理
	void AnimationControl();    //アニメーション制御
};