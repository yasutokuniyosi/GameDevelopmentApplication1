#pragma once

#define D_KEYCODE_MAX (256) //キーコードの総数

//キーボード入力管理機能		
class InputControl
{
private:
	static char now_key[D_KEYCODE_MAX];//現在フレーム入力値
	static char old_key[D_KEYCODE_MAX];//過去フレーム入力値

public:
	static void Update();                 //更新処理

	static bool GetKey(int key_code);     //押し続けている間
	static bool GetKeyDown(int key_code); //押した瞬間
	static bool GetKeyUp(int key_code);	  //離した瞬間

private:
	//キー配列範囲チェック
	static bool CheckKeyCodeRange(int key_code);
};