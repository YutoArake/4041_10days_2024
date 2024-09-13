#include "GameDemoScene.h"
#include "SceneManager.h"

void GameDemoScene::Initialize()
{
	page = 1;
	// 画像データ
	infoGraph1_ = LoadGraph("Resources/textures/setumei1.png");
	infoGraph2_ = LoadGraph("Resources/textures/setumei2.png");
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
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN] && page == 2)
	{
		// ステージセレクトへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		//BGM停止
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