#pragma once

#include <map>
#include <string>
#include <vector>

//���\�[�X���Ǘ�����N���X(�摜�Ƃ���)
class ResourceManager
{
private:
	//���N���X�̃|�C���^�i�A�h���X�̐�ɃC���X�^���X�𐶐�����j
	static ResourceManager* instance;

	//�ǂݍ��񂾉摜��ۑ����Ă郊�X�g
	std::map<std::string, std::vector<int>> image_container;

private:
	//�R���X�g���N�^��private�ɂ��邱�ƂŁA
	//���N���X�̃����o�֐��ł����C���X�^���X�𐶐��ł��Ȃ��悤�ɂ���
	ResourceManager() = default;

	//�R�s�[�K�[�h
	//�N���X�O�ŃC���X�^���X�𐶐����ēn�����Ƃ��ł��Ȃ��悤�ɂ���
	ResourceManager(ResourceManager& v) = delete;
	ResourceManager& operator = (const ResourceManager& v) = delete;
	//�`�R�s�[�K�[�h

public:
	~ResourceManager() = default;

public:
	//�C���X�^���X�擾���鏈��
	static ResourceManager* GetInstance();
	//�C���X�^���X�폜���鏈��
	static void DeleteInstance();

public:
	///<summary>
	///�摜�擾����
	/// </summary>
	/// <param name="file_path">�摜�̃t�@�C���p�X</param>
	/// <returns>�����摜�̔z��f�[�^</returns>
	const std::vector<int>& GetImages(std::string file_path);
	
	///<summary>
	///�摜�擾����
	/// </summary>
	/// <param name="file_path">�摜�̃t�@�C���p�X</param>
	/// <param name="all_num">����������</param>
	/// <param name="x_num">�������̕�����</param>
	/// <param name="y_num">�c�����̕�����</param>
	/// <param name="x_size">�����摜�P��������̃s�N�Z����(��)</param>
	/// <param name="y_size">�����摜�P��������̃s�N�Z����(�c)</param>
	/// <returns>�����摜�̔z��f�[�^</returns>
	const std::vector<int>& GetImages(std::string file_path,int all_num,int x_num,int y_num,int x_size,int y_size);

	//�ǂݍ��񂾉摜�̑S�폜
	void DeleteImages();
};