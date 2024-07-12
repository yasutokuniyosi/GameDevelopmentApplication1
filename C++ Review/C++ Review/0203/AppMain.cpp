#include "DxLib.h"
#include "Utility/InputControl.h"
#include "Objects/GameObject.h"
#include "Objects/Player/Player.h"

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

	GameObject* objects[2] = { nullptr,nullptr };
	objects[0] = new GameObject();   //自動で動くオブジェクト
	objects[1] = new Player();       //操作するオブジェクト

	//オブジェクトの初期化処理
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Initialize(); 
	}

	//描画先を裏画面に設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームメインループ
	while (ProcessMessage() != -1 && InputControl::GetKeyUp(KEY_INPUT_ESCAPE) == false)
	{
		InputControl::Update();  //キーボード入力管理機能の更新処理

		//オブジェクトの更新処理
		for (int i = 0; i < 2; i++) 
		{
			objects[i]->Update(); 
		}

		ClearDrawScreen();       //画面の削除

		//オブジェクトの描画処理
		for (int i = 0; i < 2; i++)
		{
			objects[i]->Draw();  
		}

		ScreenFlip();            //画面の更新

		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}

	//オブジェクトの削除
	for (int i = 0; i < 2; i++)
	{
		objects[i]->Finalize();
		delete objects[i];
	}

	DxLib_End();   //Dxライブラリの終了処理

	return 0;//正常終了を通知
}