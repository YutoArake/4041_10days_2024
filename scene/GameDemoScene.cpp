#include "GameDemoScene.h"
#include "SceneManager.h"

void GameDemoScene::Initialize()
{
}

void GameDemoScene::Finalize()
{
}

void GameDemoScene::Update(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_ESCAPE] == true &&
		oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("TITLE");
		return;
	}
}

void GameDemoScene::Draw()
{
}