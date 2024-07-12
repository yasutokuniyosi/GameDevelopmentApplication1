#include "InputControl.h"
#include "DxLib.h"

//静的メンバ変数定義
char InputControl::now_key[D_KEYCODE_MAX] = {};
char InputControl::old_key[D_KEYCODE_MAX] = {};

//入力機能 : 更新処理
void InputControl::Update()
{
	//前フレームの入力情報に現在の入力情報をコピーする
	memcpy(old_key, now_key, (sizeof(char) * D_KEYCODE_MAX));

	//現在の入力情報を更新する
	GetHitKeyStateAll(now_key);
}

//キー取得:押している間
bool InputControl::GetKey(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == TRUE));
}

//キー取得:押した瞬間
bool InputControl::GetKeyDown(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == TRUE) &&
		(old_key[key_code] == FALSE));
}

//キー取得:離した瞬間瞬間
bool InputControl::GetKeyUp(int key_code)
{
	return CheckKeyCodeRange(key_code) && ((now_key[key_code] == FALSE) &&
		(old_key[key_code] == TRUE));
}

//キー配列範囲チェック
bool InputControl::CheckKeyCodeRange(int key_code)
{
	return (0 <= key_code && key_code < D_KEYCODE_MAX);
}