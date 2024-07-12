#pragma once

#include "../Utility/Vector2D.h"

//ゲームオブジェクトクラス
class GameObject
{
protected:
	Vector2D location;     //位置
	Vector2D box_size;     //箱の大きさ
	int image;             //描画する画像データ
	int flip_flag;         //描画反転フラグ

public:
	GameObject();          //コンストラクタ
	virtual ~GameObject(); //デストラクタ

	virtual void Initialize();//初期化処理
	virtual void Update();    //更新処理
	virtual void Draw() const;//描画処理
	virtual void Finalize();  //終了処理

public:
	void SetLocation(const Vector2D location);//locationのセッター
	Vector2D GetLocation() const;//locationのゲッター
	Vector2D GetBoxSize() const; //BoxSizeのゲッター
};