#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// BGMデータ
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
}

void GameOverScene::Finalize()
{
}

void GameOverScene::Update(char keys[256], char oldkeys[256])
{
	//BGMが鳴っていなかったら
	if (CheckSoundMem(overBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(overBgmHandle_, DX_PLAYTYPE_BACK);
	}
}

void GameOverScene::Draw()
{
}