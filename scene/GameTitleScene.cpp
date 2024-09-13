#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
	// �摜�f�[�^
	titleGraph_ = LoadGraph("Resources/textures/title.png");
	//�^�C�g��BGM
	titleBgmHandle_ = LoadSoundMem("BGM/title.mp3");
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
		// ������ʂ�
		SceneManager::GetInstance()->ChangeScene("DEMO");
		//BGM��~
		StopSoundMem(titleBgmHandle_);
		return;
	}
}

void GameTitleScene::Draw()
{
	DrawGraph(0, 0, titleGraph_, false);
}