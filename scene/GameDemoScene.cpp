#include "GameDemoScene.h"
#include "SceneManager.h"

void GameDemoScene::Initialize()
{
	// 画像データ
	infoGraph_ = LoadGraph("Resources/textures/title.png");
	//タイトルBGM
	titleBgmHandle_ = LoadSoundMem("BGM/title.mp3");
}

void GameDemoScene::Finalize()
{
}

void GameDemoScene::Update(char keys[256], char oldkeys[256])
{
	//BGMが鳴っていなかったら
	if (CheckSoundMem(titleBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(titleBgmHandle_, DX_PLAYTYPE_BACK);
	}

	// シーン切り替え
	if (keys[KEY_INPUT_ESCAPE] && !oldkeys[KEY_INPUT_ESCAPE]) {
		// タイトルへ
		SceneManager::GetInstance()->ChangeScene("TITLE");
		//BGM停止
		StopSoundMem(titleBgmHandle_);
		return;
	}
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// ステージセレクトへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		//BGM停止
		StopSoundMem(titleBgmHandle_);
		return;
	}
}

void GameDemoScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 0, 0), "demo");
	DrawGraph(0, 0, infoGraph_, false);
}