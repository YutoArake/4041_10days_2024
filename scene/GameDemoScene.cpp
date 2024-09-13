#include "GameDemoScene.h"
#include "SceneManager.h"

void GameDemoScene::Initialize()
{
	page = 1;
	// �摜�f�[�^
	infoGraph1_ = LoadGraph("Resources/textures/setumei1.png");
	infoGraph2_ = LoadGraph("Resources/textures/setumei2.png");
	//�^�C�g��BGM
	titleBgmHandle_ = LoadSoundMem("BGM/title.mp3");
}

void GameDemoScene::Finalize()
{
}

void GameDemoScene::Update(char keys[256], char oldkeys[256])
{
	//BGM�����Ă��Ȃ�������
	if (CheckSoundMem(titleBgmHandle_) == 0)
	{
		//�Đ�
		PlaySoundMem(titleBgmHandle_, DX_PLAYTYPE_BACK);
	}

	// �V�[���؂�ւ�
	if (keys[KEY_INPUT_ESCAPE] && !oldkeys[KEY_INPUT_ESCAPE]) {
		// �^�C�g����
		SceneManager::GetInstance()->ChangeScene("TITLE");
		//BGM��~
		StopSoundMem(titleBgmHandle_);
		return;
	}
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN] && page == 2)
	{
		// �X�e�[�W�Z���N�g��
		SceneManager::GetInstance()->ChangeScene("SELECT");
		//BGM��~
		StopSoundMem(titleBgmHandle_);
		return;
	}
	else if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN]) {
		page = 2;
	}
}

void GameDemoScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 0, 0), "demo");
	if (page == 1)DrawGraph(0, 0, infoGraph1_, false);
	if (page == 2)DrawGraph(0, 0, infoGraph2_, false);
}