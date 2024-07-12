#include "ResourceManager.h"
#include "DxLib.h"

//�ǂݍ��񂾉摜��ۑ����Ă郊�X�g
ResourceManager resource_manager;

//�R���X�g���N�^
ResourceManager* GetResourceManager()
{
	return &resource_manager;
}

//�R���X�g���N�^
ResourceManager::ResourceManager() : image_container()
{
}

//�f�X�g���N�^
ResourceManager::~ResourceManager()
{

}

//�p�X�̉摜��ǂݍ���łŕԂ�(�P��摜)
const std::vector<int>& ResourceManager::GetImages(std::string file_path)
{
	//�����̃p�X���ǂݍ��܂�Ă��邩�m�F
	if (image_container.count(file_path) == NULL)
	{
		//�ǂݍ��܂�ĂȂ��̂ŉ摜�f�[�^��ǂݍ��݂܂�
		int handle = LoadGraph(file_path.c_str());

		if (handle == -1)
		{
			//�ǂݍ��ݎ��s
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���");
		}

		//�ǂݍ��߂���A�t�@�C���̃L�[�Ƀf�[�^���쐬
		image_container[file_path].push_back(handle);
	}

	//�ǂݍ��܂�Ă���摜��Ԃ�
	return image_container[file_path];
}

const std::vector<int>& ResourceManager::GetImages(std::string file_path, int all_num, int x_num, int y_num, int x_size, int y_size)
{
	//�����̃p�X���ǂݍ��܂�Ă��邩�m�F
	if (image_container.count(file_path) == NULL)
	{
		//�ǂݍ��܂�ĂȂ��̂ŉ摜�f�[�^��ǂݍ��݂܂�
		int* handle = new int[all_num];
		int result = LoadDivGraph(file_path.c_str(), all_num, x_num, y_num, x_size, y_size, handle);
		
		if (result == -1)
		{
			//�ǂݍ��ݎ��s
			throw(file_path + "�̉摜���ǂݍ��߂܂���ł���");
		}

		//�ǂݍ��߂���A�t�@�C���̃L�[�Ƀf�[�^���쐬
		for (int i = 0; 1 < all_num; i++)
		{
			image_container[file_path].push_back(handle[i]);
		}

		delete[] handle;
	}

	//�ǂݍ��܂�Ă���摜��Ԃ�
	return image_container[file_path];
}

void ResourceManager::DeleteImages()
{
	//�摜���Ȃ���ΏI��
	if (image_container.size() == NULL)
	{
		return;
	}

	//���ׂẲ摜���폜����
	for (std::pair<std::string, std::vector<int>> value : image_container)
	{
		DeleteSharingGraph(value.second[0]);
		value.second.clear();
	}

	//���I�z��̏�����
	image_container.clear();
}
