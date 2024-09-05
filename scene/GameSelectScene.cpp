#include "GameSelectScene.h"
#include "SceneManager.h"
#include <algorithm>

void GameSelectScene::Initialize()
{
}

void GameSelectScene::Finalize()
{
}

void GameSelectScene::Update(char keys[256] , char oldkeys[256])
{
	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// ゲームプレイシーンへ
		SceneManager::GetInstance()->ChangeScene("PLAY");
		return;
	}

	if (keys[KEY_INPUT_ESCAPE] == true &&
		oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("TITLE");
		return;
	}

}

void GameSelectScene::Draw()
{
}