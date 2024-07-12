#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player.h"

//メイン関数（プログラムはここから始まります。）
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;  //初期化失敗
	}

	//描画先を裏画面に設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームオブジェクトの生成
	GameObject* object1 = new GameObject();

	//プレイヤーの生成
	Player* object2 = new Player();

	//オブジェクトの初期化処理
	object1->Initialize();

	//プレイヤーの生成
	object2->Initialize();

	//ゲームメインループ
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();  //キーボード入力管理機能の更新処理

		object1->Update();       //ゲームオブジェクトの更新処理
		object2->Update();       //プレイヤーの更新処理

		ClearDrawScreen();       //画面の削除

		object1->Draw();         //ゲームオブジェクトの描画処理
		object2->Draw();         //プレイヤーの描画処理

		ScreenFlip();            //画面の更新

	}

	delete object1;     //ゲームオブジェクトの削除
	delete object2;     //プレイヤーの削除

	DxLib_End();   //Dxライブラリの終了処理

	return 0;//正常終了を通知
}