#pragma once
#define D_PIBOT_CENTER
#include <vector>
#include <string>
#include "../Objects/GameObject.h"

class Scene
{
private:
	std::vector<GameObject*> objects;//オブジェクトリスト
	int BackGround;         //背景画像
	int Stop;               //ゲームを止める
	int timer;              //フレームタイマー
	int timer_count;        //残り時間
	int number_image[10];   //数字画像
	int timer_image;        //時計画像
	int finish_image;       //終了画像

public:
	Scene();
	~Scene();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	//当たり判定チェック処理
	void HitCheckObject(GameObject* a, GameObject* b);

	//オブジェクト生成処理
	template <class T>
	T* CreateObject(const Vector2D& location)
	{
		//指定したクラスを生成する
		T* new_instance = new T();
		//GameObjectクラスを継承しているか確認
		GameObject* new_object = dynamic_cast<GameObject*>(new_instance);

		//エラーチェック
		if (new_object == nullptr)
		{
			delete new_instance;
			throw std::string("ゲームオブジェクトが生成できませんでした");
		}

		//位置情報の設定
		new_object->SetLocation(location);

		//初期化処理
		new_object->Initialize();

		//オブジェクトリストに追加
		objects.push_back(new_object);

		//インスタンスのポインタを返却
		return new_instance;
	}
};