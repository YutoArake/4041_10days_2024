#include "GameDemoScene.h"
#include "SceneManager.h"

void GameDemoScene::Initialize()
{
	meteor.Initialize();
}

void GameDemoScene::Finalize()
{
}

void GameDemoScene::Update(char keys[256], char oldkeys[256])
{
	meteor.Update();

	if (keys[KEY_INPUT_ESCAPE] == true &&
		oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("TITLE");
		return;
	}
}

void GameDemoScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 0, 0), "demo");
	meteor.Draw();
}