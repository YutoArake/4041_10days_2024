#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
	// �摜�f�[�^
	titleGraph_ = LoadGraph("Resources/textures/title.png");
	titleBgmHandle_ = LoadSoundMem("BGM/title.mp3"); //�^�C�g��BGM
}

void GameTitleScene::Finalize()
{
}

void GameTitleScene::Update(char keys[256] , char oldkeys[256])
{
	//BGM�����Ă��Ȃ�������
	if (CheckSoundMem(titleBgmHandle_) == 0)
	{
		//�Đ�
		PlaySoundMem(titleBgmHandle_, DX_PLAYTYPE_BACK);
	}
	
	// �V�[���؂�ւ�
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// �X�e�[�W�Z���N�g��
		SceneManager::GetInstance()->ChangeScene("SELECT");
		//BGM��~
		StopSoundMem(titleBgmHandle_);
		return;
	}
}

void GameTitleScene::Draw()
{
	DrawGraph(0, 0, titleGraph_, false);
	DrawFormatString(0, 0, GetColor(255, 0, 0), "title");
}