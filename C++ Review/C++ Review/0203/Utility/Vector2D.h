#pragma once

//2次元ベクトルクラス
class Vector2D
{
public:
	float x;   //x成分
	float y;   //y成分

public:
	Vector2D();                    //コンストラクタ
	Vector2D(float scalar);        //コンストラクタ
	Vector2D(float mx, float my);  //コンストラクタ
	~Vector2D();                   //ディストラクタ

public:
	//演算子オーバーロードを使っている
	Vector2D& operator = (const Vector2D& location);   //代入：演算子オーバーロード

	const Vector2D operator + (const Vector2D& location) const;    //加算:演算子オーバーロード
	Vector2D& operator +=  (const Vector2D& location);             //加算代入：演算子オーバーロード

	const Vector2D operator - (const Vector2D& location) const;    //減算:演算子オーバーロード
	Vector2D& operator -=  (const Vector2D& location);             //減算代入：演算子オーバーロード

	const Vector2D operator * (const float& scalar) const;         //乗算：演算子オーバーロード
	const Vector2D operator * (const Vector2D& location) const;    //乗算：演算子オーバーロード
	Vector2D& operator *=  (const float& scalar);                  //乗算代入：演算子オーバーロード
	Vector2D& operator *=  (const Vector2D& location);             //乗算代入：演算子オーバーロード

	const Vector2D operator / (const float& scalar) const;         //除算：演算子オーバーロード
	const Vector2D operator / (const Vector2D& location) const;    //除算：演算子オーバーロード
	Vector2D& operator /=  (const float& scalar);                  //除算代入：演算子オーバーロード
	Vector2D& operator /=  (const Vector2D& location);             //除算代入：演算子オーバーロード

	/*
	*整数型データに変換
	*説明：
	* 　xとy成分を整数型に変換し、
	*引数
	*	 int* x x成分を受け取る変数
	*	 int* y y成分を受け取る変数
	*/
	void ToInt(int* x, int* y) const;
};