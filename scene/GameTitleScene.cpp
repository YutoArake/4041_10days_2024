#include "GameTitleScene.h"
#include "SceneManager.h"

void GameTitleScene::Initialize()
{
	// 画像データ
	titleGraph_ = LoadGraph("Resources/textures/title.png");
	pressEnterGraph_ = LoadGraph("Resources/textures/pressEnter.png");
	titleBgmHandle_ = LoadSoundMem("BGM/title.mp3"); //タイトルBGM

	alpha_ = 255;
	add_ = -5;
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
	
	//"press Enter"を点滅
	alpha_ += add_;

	// アルファ値が 0 か 255 になったら変化の方向を反転する
	if (alpha_ == 0 || alpha_ == 255)
	{
		add_ = -add_;
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

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
	DrawGraph(0, 750, pressEnterGraph_, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	
}