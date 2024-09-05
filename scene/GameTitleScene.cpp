#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
	titleGraph_ = LoadGraph("Resources/textures/title.png");
}

void GameTitleScene::Finalize()
{
}

void GameTitleScene::Update(char keys[256] , char oldkeys[256])
{
	// �V�[���؂�ւ�
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// �X�e�[�W�Z���N�g��
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}
}

void GameTitleScene::Draw()
{
	DrawGraph(0, 0, titleGraph_, false);
	DrawFormatString(0, 0, GetColor(255, 0, 0), "title");
}