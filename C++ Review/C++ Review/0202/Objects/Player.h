#pragma once

#include "GameObject.h"

//プレイヤー用クラス
class Player : public GameObject
{
private:

public:
	Player();            //コンストラクタ
	~Player()override;   //デストラクタ

    void Initialize() override;  //初期化処理
    void Update() override;      //更新処理
	void Draw() const override;  //描画処理
	void Finalize() override;    //終了処理

private:
	void Movement();            //移動処理
};