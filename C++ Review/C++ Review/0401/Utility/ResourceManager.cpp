#include "ResourceManager.h"
#include "DxLib.h"

//読み込んだ画像を保存してるリスト
ResourceManager* ResourceManager::instance = nullptr;

//コンストラクタ
ResourceManager* ResourceManager::GetInstance()
{
	//インスタンスが無ければ、生成する
	if (instance == nullptr)
	{
		instance = new ResourceManager();
	}

	//自分自身のポインタを返却する
	return instance;
}

//リソース管理クラスのインスタンス削除する処理
void ResourceManager::DeleteInstance()
{
	//インスタンスが存在していれば、削除する
	if (instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

//パスの画像を読み込んでで返す(単一画像)
const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	//引数のパスが読み込まれているか確認
	if (image_container.count(file_path) == NULL)
	{
		//読み込まれてないので画像データを読み込みます
		int handle = LoadGraph(file_path.c_str());

		if (handle == -1)
		{
			//読み込み失敗
			throw(file_path + "の画像が読み込めませんでした");
		}

		//読み込めたら、ファイルのキーにデータを作成
		image_container[file_path].push_back(handle);
	}

	//読み込まれている画像を返す
	return image_container[file_path];
}

const std::vector<int>& ResourceManager::GetImages(std::string file_path, int all_num, int x_num, int y_num, int x_size, int y_size)
{
	//引数のパスが読み込まれているか確認
	if (image_container.count(file_path) == NULL)
	{
		//読み込まれてないので画像データを読み込みます
		int* handle = new int[all_num];
		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num, x_size, y_size, handle);
		
		if (result == -1)
		{
			//読み込み失敗
			throw(file_path + "の画像が読み込めませんでした");
		}

		//読み込めたら、ファイルのキーにデータを作成
		for (int i = 0; 1 < all_num; i++)
		{
			image_container[file_path].push_back(handle[i]);
		}

		delete[] handle;
	}

	//読み込まれている画像を返す
	return image_container[file_path];
}

void ResourceManager::DeleteImages()
{
	//画像がなければ終了
	if (image_container.size() == NULL)
	{
		return;
	}

	//すべての画像を削除する
	for (std::pair<std::string, std::vector<int>> value : image_container)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}

	//動的配列の初期化
	image_container.clear();
}
