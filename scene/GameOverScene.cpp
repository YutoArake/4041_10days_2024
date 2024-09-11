#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// メニュー
	menu_ = RETRY_STAGE;

	// 画像データ
	bgGraph = LoadGraph("Resources/textures/select.png");
	// 音声データ
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");
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

	// メニュー切り替え
	if (keys[KEY_INPUT_RIGHT] && !oldkeys[KEY_INPUT_RIGHT])
	{
		// インクリメント
		menu_++;
		// 値がメニュー数を超えないようにする
		menu_ = std::min<int>(menu_, MENU_MAX_NUM);
	}
	if (keys[KEY_INPUT_LEFT] && !oldkeys[KEY_INPUT_LEFT])
	{
		// デクリメント
		menu_--;
		// 値が0を下回らないようにする
		menu_ = std::max<int>(menu_, 0);
	}

	// シーン切り替え
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		if (menu_ == RETRY_STAGE) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// ゲームプレイシーンへ
			SceneManager::GetInstance()->ChangeScene("PLAY");
			//BGM停止
			StopSoundMem(overBgmHandle_);
			return;
		}
		else if (menu_ == RETURN_TO_STAGESELECT) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// セレクトシーンへ
			SceneManager::GetInstance()->ChangeScene("SELECT");
			//BGM停止
			StopSoundMem(overBgmHandle_);
			return;
		}
		else if (menu_ == RETURN_TO_TITLE) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// タイトルへ
			SceneManager::GetInstance()->ChangeScene("TITLE");
			//BGM停止
			StopSoundMem(overBgmHandle_);
			return;
		}
	}
}

void GameOverScene::Draw()
{
	DrawGraph(0, 0, bgGraph, true);
	// デバックテキスト
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲームオーバーシーン");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", menu_);
}