#include "Enemy.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"


//	コンストラクタ
Enemy::Enemy() : animation_count(0), flip_flag(FALSE),animation_image(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	animation[4] = NULL;
	Enemy_Born = 1;
	Speed = 0;
}

//デストラクタ
Enemy::~Enemy()
{
}

//初期化処理
void Enemy::Initialize()
{
	//ランダムに敵を変える
	int EnemyChange = GetRand(100);

	if (location.x == 100)
	{
		flip_flag = FALSE;
	}
	if(location.x == 540)
	{
		flip_flag = TRUE;
	}

	//ハコ敵
	if (EnemyChange >= 50)
	{
		//画像の読み込み
		animation[0] = LoadGraph("Resource/Images/1 (1).png");
		animation[1] = LoadGraph("Resource/Images/2 (1).png");
		animation[2] = NULL;
		animation[3] = NULL;
		animation[4] = NULL;

		//Y座標は固定
		location.y = 400.0f;
	}
	//
	else if (EnemyChange < 30)
	{
		//画像の読み込み
		animation[0] = LoadGraph("Resource/Images/1.png");
		animation[1] = LoadGraph("Resource/Images/2.png");
		animation[2] = NULL;
		animation[3] = NULL;
		animation[4] = NULL;
		//座標を少し下げる
		location.y -= 50.0f;
	}
	//レア敵
	else if (30<=EnemyChange < 40)
	{
		//画像の読み込み
		animation[0] = LoadGraph("Resource/Images/1 (3).png");
		animation[1] = LoadGraph("Resource/Images/2 (3).png");
		animation[2] = LoadGraph("Resource/Images/3.png");
		animation[3] = LoadGraph("Resource/Images/4.png");
		animation[4] = LoadGraph("Resource/Images/5.png");

		//Y座標は固定
		location.y = 400.0f;

		//スピードを１獲得
		Speed = 1;
	}

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("箱敵の画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = (64.0f);

	//初期化画像の設定
	image = animation[animation_image];

	//識別番号は２
	w = 2;
}

//更新処理
void Enemy::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();
}

//描画処理
void Enemy::Draw() const
{
	
	//敵の画像の描画
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);
	
//デバッグ用
#if _DEBUG
	//当たり判定の可視化
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif

	//親クラスの描画処理を呼び出す
	__super::Draw();
}

//終了処理
void Enemy::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
	DeleteGraph(animation[4]);
}

//当たり判定通知処理
void Enemy::OnHitCollision(GameObject* hit_object)
{
	//識別番号３（爆弾）が当たった時の処理
	if (hit_object->read() == 3)
	{
		//デリートフラグをTRUEにする
		Delete_flag = TRUE;
	}
}


//移動処理
void Enemy::Movement()
{
	Vector2D velocity = 0.0f;
	if (flip_flag == FALSE)
	{
		if (location.x >= 500)
		{

			Delete_flag = TRUE;
		}
		else if (location.x <= 500)
		{
			//右移動
			//移動方向決定
			//レア敵は速さ2倍
			if (Speed == 1)
			{
				velocity.x = 2.0f;
			}
			else
			{
				velocity.x = 1.0f;
			}
		}
		else
		{
			velocity.x = 0.0f;
		}
	}

	else if (flip_flag == TRUE)
	{
		if (location.x <= 100)
		{

			Delete_flag = TRUE;
		}
		else if (location.x >= 100)
		{
			//左移動
			//移動方向決定
			//レア敵は速さ2倍
			if (Speed == 1)
			{
				velocity.x = -2.0f;
			}
			else 
			{
				velocity.x = -1.0f;
			}
		}
		else
		{
			velocity.x = 0.0f;
		}
	}

	

	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Enemy::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;
		animation_image++;

		//画像の切替
		if (animation[animation_image] == NULL)
		{
			image = animation[0];
			animation_image = 0;
		}
		else
		{
			image = animation[animation_image];
		}
		
	    //if (image == animation[0])
		//{
			//image = animation[1];
		//}
		//else
		//{
			//image = animation[0];
		//}
	}
}