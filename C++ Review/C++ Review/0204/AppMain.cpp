#include "DxLib.h"
#include "Utility/ResourceManager.h"
#include "Utility/InputControl.h"
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

	//プレイヤーを生成する
	GameObject* object = new Player();
	ResourceManager* resource_manager = GetResourceManager();

	//描画先を裏画面に設定する
	SetDrawScreen(DX_SCREEN_BACK);
	try
	{
		object->Initialize();

		//ゲームメインループ
		while (ProcessMessage() != -1)
		{
			InputControl::Update();  //キーボード入力管理機能の更新処理

	        object->Update(); //オブジェクトの更新処理

			ClearDrawScreen();       //画面の削除

			object->Draw();          //オブジェクトの描画処理

			ScreenFlip();            //画面の更新

			if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
			{
				break;
			}
		}
	}

	//エラーのログをデバックの外に書く
	catch (std::string error_log)
	{
		OutputDebugString(error_log.c_str());
	}

	object->Finalize();//オブジェクトの終了処理

	delete object;//オブジェクトの削除

	resource_manager->DeleteImages();//リソースの削除処理

	DxLib_End();   //Dxライブラリの終了処理

	return 0;//正常終了を通知
}