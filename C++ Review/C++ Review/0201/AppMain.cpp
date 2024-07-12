#include "DxLib.h"
#include "Utility/InputControl.h"
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

	//プレイヤーを生成する
	Player* player = new Player();

	//描画先を裏画面に設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//入力情報
		InputControl::Update();

		//プレイヤーの更新処理
		player->Update();

		
		//壁に触れたら反対側の壁に移動する処理
		Vector2D tmp = player->GetLocation();
		if (tmp.x < 0.0f || 640.0f < tmp.x)
		{
			if (tmp.x < 0)
			{
				tmp.x = 640.0f;          //左の壁から右の壁へ
			}
			else
			{
				tmp.x = 0.0f;            //右の壁から左の壁へ
			}
			player->SetLocation(tmp);
		}

		if (tmp.y < 0.0f || 480.0f < tmp.y)
		{
			if (tmp.y < 0)
			{
				tmp.y = 480.0f;          //上の壁から下の壁へ
			}
			else
			{
				tmp.y = 0.0f;            //下の壁から上の壁へ
			}
		}
		player->SetLocation(tmp);//座標の更新

		ClearDrawScreen();  //画面の削除

		player->Draw();     //描画処理

		ScreenFlip();       //画面の更新

		//終了ボタン処理
		if (InputControl::GetKeyUp(KEY_INPUT_ESCAPE))
		{
			break;
		}
	}
	delete player;//プレイヤーのデータ削除

	DxLib_End();//DXライブラリの終了処理

	//正常終了を通知
	return 0;
}