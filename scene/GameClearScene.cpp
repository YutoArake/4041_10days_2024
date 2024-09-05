#include "GameClearScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GameClearScene::Initialize()
{
	// メニュー
	menu_ = NEXT_STAGE;
	if (GameSelectScene::stageNum_ == GameSelectScene::STAGE_MAX_NUM) {
		menu_ = RETURN_TO_STAGESELECT;
	}

	// 画像データ
	bgGraph = LoadGraph("Resources/textures/bg.png");

	// 音データ
	//musicHandle = LoadSoundMem("Resources/sounds/.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");
}

void GameClearScene::Finalize()
{
}

void GameClearScene::Update(char keys[256] , char oldkeys[256])
{
	// メニュー切り替え
	if (keys[KEY_INPUT_DOWN] && !oldkeys[KEY_INPUT_DOWN])
	{
		// インクリメント
		menu_++;
		// 値がメニュー数を超えないようにする
		menu_ = std::min<int>(menu_, MENU_MAX_NUM);
	}
	if (keys[KEY_INPUT_UP] && !oldkeys[KEY_INPUT_UP])
	{
		// デクリメント
		menu_--;

		if (GameSelectScene::stageNum_ < GameSelectScene::STAGE_MAX_NUM) {
			// 値が0を下回らないようにする
			menu_ = std::max<int>(menu_, 0);
		}
		else {
			// 値が1を下回らないようにする
			menu_ = std::max<int>(menu_, 1);
		}
	}

	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		if (menu_ == NEXT_STAGE) {
			// 効果音
			PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// ゲームプレイシーンへ
			GameSelectScene::stageNum_++;
			SceneManager::GetInstance()->ChangeScene("PLAY");
			return;
		}
		else if (menu_ == RETURN_TO_STAGESELECT) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// セレクトシーンへ
			SceneManager::GetInstance()->ChangeScene("SELECT");
			return;
		}
		else if (menu_ == RETURN_TO_TITLE) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// タイトルへ
			SceneManager::GetInstance()->ChangeScene("TITLE");
			return;
		}
	}
}

void GameClearScene::Draw()
{
	DrawGraph(0, 0, bgGraph, true);
}