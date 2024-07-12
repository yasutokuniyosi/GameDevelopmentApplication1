#pragma once

#define D_KEYCODE_MAX (256) //キーコードの総数

//キーボード入力管理機能		
class InputControl
{
private:
	static InputControl* instance;

	char now_key[D_KEYCODE_MAX];//現在フレーム入力値
    char old_key[D_KEYCODE_MAX];//過去フレーム入力値

private:
	InputControl() = default;

	InputControl(InputControl& v) = delete;
	InputControl& operator = (const InputControl& v) = delete;

public:
	~InputControl() = default;

public:
	static InputControl* GetInstance();
	static void DeleteInstance();
public:
	void Update();                 //更新処理

	bool GetKey(int key_code)const;     //押し続けている間
	bool GetKeyDown(int key_code)const; //押した瞬間
    bool GetKeyUp(int key_code) const;	  //離した瞬間

private:
	//キー配列範囲チェック
	bool CheckKeyCodeRange(int key_code) const;
};