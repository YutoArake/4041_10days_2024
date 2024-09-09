#include "GamePlayScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	stage.Initialize(GameSelectScene::stageNum_);
}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	stage.Update();

	if (keys[KEY_INPUT_ESCAPE] == true && oldkeys[KEY_INPUT_ESCAPE] == false)
	{
		// ステージセレクトへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}
}

void GamePlayScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
	stage.Draw();
}