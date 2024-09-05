#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
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
	DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}