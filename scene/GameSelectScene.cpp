#include "GameSelectScene.h"
#include "SceneManager.h"
#include <algorithm>

/// <summary>
/// 静的メンバ変数の実体
/// </summary>
int GameSelectScene::stageNum_ = 1;

void GameSelectScene::Initialize()
{
	// 画像データ
	bgGraph = LoadGraph("Resources/textures/select.png");
	rocketGraph = LoadGraph("Resources/textures/player.png");
	//セレクトBGM
	selectBgmHandle_ = LoadSoundMem("BGM/select.mp3"); 

	// 音データ
	//musicHandle = LoadSoundMem("Resources/sounds/.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");
}

void GameSelectScene::Finalize()
{
}

void GameSelectScene::Update(char keys[256] , char oldkeys[256])
{
	//BGMが鳴っていなかったら
	if (CheckSoundMem(selectBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(selectBgmHandle_, DX_PLAYTYPE_BACK);
		//音量小さめ
		ChangeVolumeSoundMem(100, selectBgmHandle_);
	}

	// マップ切り替え
	if (keys[KEY_INPUT_DOWN] && !oldkeys[KEY_INPUT_DOWN])
	{
		// インクリメント
		stageNum_++;
		// 値がマップ数を超えないようにする
		stageNum_ = std::min<int>(stageNum_, STAGE_MAX_NUM);
	}
	if (keys[KEY_INPUT_UP] && !oldkeys[KEY_INPUT_UP])
	{
		// デクリメント
		stageNum_--;
		// 値が1を下回らないようにする
		stageNum_ = std::max<int>(stageNum_, 1);
	}

	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		//BGM停止
		StopSoundMem(selectBgmHandle_);
		// 効果音
		//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
		// ゲームプレイシーンへ
		SceneManager::GetInstance()->ChangeScene("PLAY");
		return;
	}

	if (keys[KEY_INPUT_ESCAPE] && !oldkeys[KEY_INPUT_ESCAPE])
	{
		// タイトルへ
		SceneManager::GetInstance()->ChangeScene("TITLE");
		return;
	}
}

void GameSelectScene::Draw()
{
	// 背景
	DrawGraph(0, 0, bgGraph, false);

	// ステージ選択
	int radius = 64;
	if (stageNum_ == 1) DrawExtendGraph(150, 500, 150 + radius * 2, 500 + radius * 2, rocketGraph, false);
	else if(stageNum_ == 2) DrawExtendGraph(575, 500, 575 + radius * 2, 500 + radius * 2, rocketGraph, false);
	else if(stageNum_ == 3) DrawExtendGraph(1000, 500, 1000 + radius * 2, 500 + radius * 2, rocketGraph, false);

	// デバックテキスト
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", stageNum_);
}