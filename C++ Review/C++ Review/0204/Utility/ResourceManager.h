#pragma once

#include <map>
#include <string>
#include <vector>

//���\�[�X���Ǘ�����N���X(�摜�Ƃ���)
class ResourceManager
{
private:
	//�ǂݍ��񂾉摜��ۑ����Ă郊�X�g
	std::map<std::string, std::vector<int>> image_container;

public:
	ResourceManager();          //�R���X�g���N�^
	~ResourceManager();         //�f�X�g���N�^

	//�p�X�̉摜��ǂݍ���łŕԂ�(�P��摜)
	const std::vector<int>& GetImages(std::string file_path);

	//�p�X�̉摜��ǂݍ���łŕԂ�(�����摜)
	const std::vector<int>& GetImages(std::string file_path,int all_num,int x_num,int y_num,int x_size,int y_size);

	//�ǂݍ��񂾉摜�̑S�폜
	void DeleteImages();
};

//ResourceManager�̃I�u�W�F�N�g���擾����Q�b�^�[
ResourceManager* GetResourceManager();