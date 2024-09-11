#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// BGMƒf[ƒ^
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
}

void GameOverScene::Finalize()
{
}

void GameOverScene::Update(char keys[256], char oldkeys[256])
{
	//BGM‚ª–Â‚Á‚Ä‚¢‚È‚©‚Á‚½‚ç
	if (CheckSoundMem(overBgmHandle_) == 0)
	{
		//Ä¶
		PlaySoundMem(overBgmHandle_, DX_PLAYTYPE_BACK);
	}
}

void GameOverScene::Draw()
{
}