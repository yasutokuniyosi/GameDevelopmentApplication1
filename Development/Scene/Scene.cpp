#include "Scene.h"

#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Bom/Bom.h"
#include <DxLib.h>
#include "../../Utility/InputControl.h"

#define D_PIVOT_CENTER

//コンストラクタ
Scene::Scene() : BackGround(NULL),timer()
{
	BackGround = NULL;
	Stop = FALSE;
	timer_count = 60;
}

//デストラクタ
Scene::~Scene()
{
	//解放忘れ防止
	Finalize();
}

//更新処理
void Scene::Update()
{
	//ランダムにEnemyを生成する
	int CreateEnemy = GetRand(200);

	//ランダムにEnemyのｙ座標を決める
	int RandamEnemy = GetRand(150);

	if (Stop == FALSE)
	{
		if (CreateEnemy == 1)
		{
			//Enemyを生成する
			CreateObject<Enemy>(Vector2D(100.0f, 250.0f + RandamEnemy));
		}

		if (CreateEnemy == 2)
		{
			//Enemyを生成する
			CreateObject<Enemy>(Vector2D(540.0f, 250.0f + RandamEnemy));
		}

		if (InputControl::GetKeyDown(KEY_INPUT_SPACE))//スペースボタンを押したらっていう条件式
		{
			//爆弾を生成する
			CreateObject<Bom>(Vector2D(objects[0]->GetLocation()));//最初に生成されるオブジェクトから生成される
		}

		//シーンに存在するオブジェクトの更新処理
		for (GameObject* obj : objects)
		{
			obj->Update();
		}

		//オブジェクト同士の当たり判定チェック
		for (int i = 0; i < objects.size(); i++)
		{
			for (int j = i + 1; j < objects.size(); j++)
			{
				//当たり判定チェック処理
				HitCheckObject(objects[i], objects[j]);
			}
		}
		//フラグを出したオブジェクトだけ消す処理
		for (int i = 0; i < objects.size(); i++)
		{
			if (objects[i]->GetDelete_flag() == TRUE)
			{
				//オブジェクトの削除
				objects.erase(objects.begin() + i);
			}
		}

		//フレームタイマーを加算
		timer++;
		//フレームタイマーが120になったら、残り時間を減らす
		if (timer == 120)
		{
			timer_count--;
			timer = 0;
		}
		//残り時間がゼロになったらオブジェクトを消す
		if (timer_count < 0)
		{
			objects.clear();
		}
	}
	
}

//初期化処理
void Scene::Initialize()
{ 
	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(320.0f, 70.0f));

	//背景を生成する
	BackGround = LoadGraph("Resource/images/BackGround.png");

	//数字の画像を読み取る
	number_image[0] = LoadGraph("Resource/images/Number/0.png");
	number_image[1] = LoadGraph("Resource/images/Number/1.png");
	number_image[2] = LoadGraph("Resource/images/Number/2.png");
	number_image[3] = LoadGraph("Resource/images/Number/3.png");
	number_image[4] = LoadGraph("Resource/images/Number/4.png");
	number_image[5] = LoadGraph("Resource/images/Number/5.png");
	number_image[6] = LoadGraph("Resource/images/Number/6.png");
	number_image[7] = LoadGraph("Resource/images/Number/7.png");
	number_image[8] = LoadGraph("Resource/images/Number/8.png");
	number_image[9] = LoadGraph("Resource/images/Number/9.png");

	//時計の画像を読み取る
	timer_image = LoadGraph("Resource/images/timer-03.png");

	//フィニッシュの画像を読み取る
	finish_image = LoadGraph("Resource/images/Finish.png");
}

//描画処理
void Scene::Draw()const
{
	//背景の描画
	DrawExtendGraphF(0,0,640,480,BackGround,FALSE);

	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}

	//時計画像の描画
	DrawRotaGraph(20, 460,0.7,0,timer_image,TRUE,FALSE);

	//残り時間がゼロ未満になるまで残り時間を描画する
	if (timer_count > 0)
	{
		//残り時間の1桁目を描画
		DrawRotaGraph(70, 460, 1.5,0,number_image[timer_count % 10], TRUE);

		//残り時間の2桁目を描画
		DrawRotaGraph(50, 460, 1.5,0,number_image[timer_count / 10], TRUE);
	}

	//残り時間がゼロ未満になるまでフィニッシュを表示する
	if (timer_count < 0)
	{
		//フィニッシュを表示
		DrawRotaGraph(320, 240, 0.7, 0, finish_image, TRUE, FALSE);
	}
}

//終了時処理
void Scene::Finalize()
{
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを排除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	objects.clear();
}

#ifdef D_PIBOT_CENTER

//当たり判定チェック処理（矩形の中心であったり判定をとる）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2つのオブジェクトの当たり判定の大きさを取得
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//距離より大きさが大きい場合、Hit判定とする
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//当たったことをオブジェクトに通知する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#else

//当たり判定チェック処理(左上頂点の座標から当たり判定計算を行う）
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//左上頂点座標を取得する
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//矩形Aと矩形Bの位置関係を調べる
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//オブジェクトに対してHit判定を取得する
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CNETER