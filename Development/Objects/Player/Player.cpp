#include "Player.h"
#include "../../Utility/InputControl.h"
#include "DxLib.h"

//	コンストラクタ
Player::Player() : animation_count(0), flip_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
}

//デストラクタ
Player::~Player()
{
}

//初期化処理
void Player::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/images/Tripilot1.png");
	animation[1] = LoadGraph("Resource/images/Tripilot2.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("鳥パイロットの画像がありません\n");
	}

	//向きの設定
	radian = 0.0f;

	//当たり判定の大きさを設定
	box_size = (64.0f);
		
	//初期化画像の設定
	image = animation[0];

	//識別番号は１
	w = 1;
}

//更新処理
void Player::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimationControl();
}

//描画処理
void Player::Draw() const
{
	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 0.7, radian, image, TRUE, flip_flag);

//デバッグ用
#if _DEBUG
	//当たり判定の可視化
	Vector2D ul = location - (box_size / 2.0f);
	Vector2D br = location + (box_size / 2.0f);

	DrawBoxAA(ul.x, ul.y, br.x, br.y, GetColor(255, 0, 0), FALSE);
#endif
}

//終了処理
void Player::Finalize()
{
	//使用した画像を解放
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Player::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理
}


//移動処理
void Player::Movement()
{
	Vector2D velocity = 0.0f;

	if (InputControl::GetKey(KEY_INPUT_LEFT))
	{
		//左移動
		//移動方向決定
		velocity.x += -1.0f;
		flip_flag = TRUE;
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT))
	{
		//右移動
		//移動方向決定
		velocity.x += 1.0f;
		flip_flag = FALSE;
	}
	else
	{
		velocity.x = 0.0f;
	}

	//現在の位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Player::AnimationControl()
{
	//アニメーションカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切替
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}