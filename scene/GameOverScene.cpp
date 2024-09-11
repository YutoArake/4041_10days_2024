#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// BGM�f�[�^
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
}

void GameOverScene::Finalize()
{
}

void GameOverScene::Update(char keys[256], char oldkeys[256])
{
	//BGM�����Ă��Ȃ�������
	if (CheckSoundMem(overBgmHandle_) == 0)
	{
		//�Đ�
		PlaySoundMem(overBgmHandle_, DX_PLAYTYPE_BACK);
	}
}

void GameOverScene::Draw()
{
}