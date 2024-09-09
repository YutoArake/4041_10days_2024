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
	bgGraph = LoadGraph("Resources/textures/bg.png");

	// 音データ
	//musicHandle = LoadSoundMem("Resources/sounds/.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");
}

void GameSelectScene::Finalize()
{
}

void GameSelectScene::Update(char keys[256] , char oldkeys[256])
{
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
	DrawGraph(0, 0, bgGraph, false);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "select");
}