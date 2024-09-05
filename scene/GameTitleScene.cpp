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
	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// ステージセレクトへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}
}

void GameTitleScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
}