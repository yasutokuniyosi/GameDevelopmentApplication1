#include "Scene.h"

#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Player/Player.h"
#include "../Objects/Bom/Bom.h"
#include <DxLib.h>
#include "../../Utility/InputControl.h"

#define D_PIVOT_CENTER

//�R���X�g���N�^
Scene::Scene() : BackGround(NULL),timer()
{
	BackGround = NULL;
	Stop = FALSE;
	timer_count = 60;
}

//�f�X�g���N�^
Scene::~Scene()
{
	//����Y��h�~
	Finalize();
}

//�X�V����
void Scene::Update()
{
	//�����_����Enemy�𐶐�����
	int CreateEnemy = GetRand(200);

	//�����_����Enemy�̂����W�����߂�
	int RandamEnemy = GetRand(150);

	if (Stop == FALSE)
	{
		if (CreateEnemy == 1)
		{
			//Enemy�𐶐�����
			CreateObject<Enemy>(Vector2D(100.0f, 250.0f + RandamEnemy));
		}

		if (CreateEnemy == 2)
		{
			//Enemy�𐶐�����
			CreateObject<Enemy>(Vector2D(540.0f, 250.0f + RandamEnemy));
		}

		if (InputControl::GetKeyDown(KEY_INPUT_SPACE))//�X�y�[�X�{�^��������������Ă���������
		{
			//���e�𐶐�����
			CreateObject<Bom>(Vector2D(objects[0]->GetLocation()));//�ŏ��ɐ��������I�u�W�F�N�g���琶�������
		}

		//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
		for (GameObject* obj : objects)
		{
			obj->Update();
		}

		//�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
		for (int i = 0; i < objects.size(); i++)
		{
			for (int j = i + 1; j < objects.size(); j++)
			{
				//�����蔻��`�F�b�N����
				HitCheckObject(objects[i], objects[j]);
			}
		}
		//�t���O���o�����I�u�W�F�N�g������������
		for (int i = 0; i < objects.size(); i++)
		{
			if (objects[i]->GetDelete_flag() == TRUE)
			{
				//�I�u�W�F�N�g�̍폜
				objects.erase(objects.begin() + i);
			}
		}

		//�t���[���^�C�}�[�����Z
		timer++;
		//�t���[���^�C�}�[��120�ɂȂ�����A�c�莞�Ԃ����炷
		if (timer == 120)
		{
			timer_count--;
			timer = 0;
		}
		//�c�莞�Ԃ��[���ɂȂ�����I�u�W�F�N�g������
		if (timer_count < 0)
		{
			objects.clear();
		}
	}
	
}

//����������
void Scene::Initialize()
{ 
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 70.0f));

	//�w�i�𐶐�����
	BackGround = LoadGraph("Resource/images/BackGround.png");

	//�����̉摜��ǂݎ��
	number_image[0] = LoadGraph("Resource/images/Number/0.png");
	number_image[1] = LoadGraph("Resource/images/Number/1.png");
	number_image[2] = LoadGraph("Resource/images/Number/2.png");
	number_image[3] = LoadGraph("Resource/images/Number/3.png");
	number_image[4] = LoadGraph("Resource/images/Number/4.png");
	number_image[5] = LoadGraph("Resource/images/Number/5.png");
	number_image[6] = LoadGraph("Resource/images/Number/6.png");
	number_image[7] = LoadGraph("Resource/images/Number/7.png");
	number_image[8] = LoadGraph("Resource/images/Number/8.png");
	number_image[9] = LoadGraph("Resource/images/Number/9.png");

	//���v�̉摜��ǂݎ��
	timer_image = LoadGraph("Resource/images/timer-03.png");

	//�t�B�j�b�V���̉摜��ǂݎ��
	finish_image = LoadGraph("Resource/images/Finish.png");
}

//�`�揈��
void Scene::Draw()const
{
	//�w�i�̕`��
	DrawExtendGraphF(0,0,640,480,BackGround,FALSE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}

	//���v�摜�̕`��
	DrawRotaGraph(20, 460,0.7,0,timer_image,TRUE,FALSE);

	//�c�莞�Ԃ��[�������ɂȂ�܂Ŏc�莞�Ԃ�`�悷��
	if (timer_count > 0)
	{
		//�c�莞�Ԃ�1���ڂ�`��
		DrawRotaGraph(70, 460, 1.5,0,number_image[timer_count % 10], TRUE);

		//�c�莞�Ԃ�2���ڂ�`��
		DrawRotaGraph(50, 460, 1.5,0,number_image[timer_count / 10], TRUE);
	}

	//�c�莞�Ԃ��[�������ɂȂ�܂Ńt�B�j�b�V����\������
	if (timer_count < 0)
	{
		//�t�B�j�b�V����\��
		DrawRotaGraph(320, 240, 0.7, 0, finish_image, TRUE, FALSE);
	}
}

//�I��������
void Scene::Finalize()
{
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g��r������
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	objects.clear();
}

#ifdef D_PIBOT_CENTER

//�����蔻��`�F�b�N�����i��`�̒��S�ł������蔻����Ƃ�j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	Vector2D diff = a->GetLocation() - b->GetLocation();

	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;

	//�������傫�����傫���ꍇ�AHit����Ƃ���
	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
	{
		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}

#else

//�����蔻��`�F�b�N����(���㒸�_�̍��W���瓖���蔻��v�Z���s���j
void Scene::HitCheckObject(GameObject* a, GameObject* b)
{
	//���㒸�_���W���擾����
	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
	Vector2D b_lower_right = b->GetLocation() + b->GetBoxSize();

	//��`A�Ƌ�`B�̈ʒu�֌W�𒲂ׂ�
	if ((a->GetLocation().x < b_lower_right.x) &&
		(a->GetLocation().y < b_lower_right.y) &&
		(a_lower_right.x > b->GetLocation().x) &&
		(a_lower_right.y > b->GetLocation().y))
	{
		//�I�u�W�F�N�g�ɑ΂���Hit������擾����
		a->OnHitCollision(b);
		b->OnHitCollision(a);
	}
}
#endif // D_PIVOT_CNETER