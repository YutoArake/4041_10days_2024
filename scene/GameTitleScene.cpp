#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
	// 画像データ
	titleGraph_ = LoadGraph("Resources/textures/title.png");
	//タイトルBGM
	titleBgmHandle_ = LoadSoundMem("BGM/title.mp3");
}

void GameTitleScene::Finalize()
{
}

void GameTitleScene::Update(char keys[256] , char oldkeys[256])
{
	//BGMが鳴っていなかったら
	if (CheckSoundMem(titleBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(titleBgmHandle_, DX_PLAYTYPE_BACK);
	}
	
	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		// 説明画面へ
		SceneManager::GetInstance()->ChangeScene("DEMO");
		//BGM停止
		StopSoundMem(titleBgmHandle_);
		return;
	}
}

void GameTitleScene::Draw()
{
	DrawGraph(0, 0, titleGraph_, false);
}