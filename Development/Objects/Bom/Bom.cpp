#include "Bom.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"


//	コンストラクタ
Bom::Bom() : animation_count(0), flip_flag(FALSE), animation_image(0)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	Bom_Born = 1;
	x = 0;
}

//デストラクタ
Bom::~Bom()
{
}

//初期化処理
void Bom::Initialize()
{
		//画像の読み込み
		animation[0] = LoadGraph("Resource/Images/Bom.png");
		animation[1] = LoadGraph("Resource/Images/2 (4).png");
		animation[2] = LoadGraph("Resource/Images/3 (1).png");
		animation[3] = LoadGraph("Resource/Images/1 (4).png");
	
	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("爆弾の画像がありません\n");
	}

	//向きの設定
	radian = 90*(3.14/180);

	//当たり判定の大きさを設定
	box_size = (64.0f);

	//初期化画像の設定
	image = animation[animation_image];

	//識別番号は3
	w = 3;

	//速さは２
	velocity.y = 2.0f;

	//起爆スイッチは０
	x = 0;
}

//更新処理
void Bom::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();
}

//描画処理
void Bom::Draw() const
{

	//爆弾の画像の描画
	DrawRotaGraphF(location.x, location.y, 0.7, radian , image, TRUE, flip_flag);

//デバッグ用
#if _DEBUG
	//当たり判定の可視化
	Vector2D ul = location - (scale / 2.0f);
	Vector2D br = location + (scale / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//終了処理
void Bom::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
	DeleteGraph(animation[2]);
	DeleteGraph(animation[3]);
}

//当たり判定通知処理
void Bom::OnHitCollision(GameObject* hit_object)
{
	//識別番号2（敵）が当たった時の処理
	if (hit_object->read() == 2)
	{
		//起爆スイッチを1にして爆弾の落下を止める
		x = 1;
		velocity.y = 0.0f;
	}
}


//移動処理
void Bom::Movement()
{
	//移動速度に応じて爆弾の場所を変える
	location += velocity;
	if (location.y >= 400)
	{
	    //起爆スイッチを1にして爆弾の落下を止める
		x = 1;
		velocity.y = 0.0f;
	}
}

//アニメーション制御
void Bom::AnimationControl()
{
		//アニメーションカウントを加算する
		animation_count++;
			
		//起爆スイッチが１になったら爆発のアニメーションに変える
		if (x == 1)
		{
			//20フレーム目に到達したら
			if (animation_count >= 20)
			{
				//カウントのリセット
				animation_count = 0;
				animation_image++;

				//画像の切替
				if (animation[animation_image] == NULL)
				{
					image = animation[0];
					animation_image = 0;
					//爆発のアニメーションが終わったら、デリートフラグをTRUEにする
					Delete_flag = TRUE;
					
				}
				else
				{
					radian = 0;
					image = animation[animation_image];
				}
			}
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