#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// メニュー
	menu_ = RETRY_STAGE;

	// 画像データ
	bgGraph = LoadGraph("Resources/textures/select.png");
	pGraph = LoadGraph("Resources/textures/yajirushi.png");
	retryStageGraph = LoadGraph("Resources/textures/retry.png");
	toSelectGraph = LoadGraph("Resources/textures/selectScene.png");
	toTitleGraph = LoadGraph("Resources/textures/titleScene.png");
	// 音声データ
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");

	alpha_ = 255;
	add_ = -5;
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

	// 点滅
	alpha_ += add_;

	// アルファ値が 0 か 255 になったら変化の方向を反転する
	if (alpha_ == 0 || alpha_ == 255)
	{
		add_ = -add_;
	}


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
	// 選択
	switch (menu_)
	{
	case RETRY_STAGE:
		DrawGraph(350, 325, pGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 300, retryStageGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 400, toSelectGraph, true);
		DrawGraph(0, 500, toTitleGraph, true);
		break;
	case RETURN_TO_STAGESELECT:
		DrawGraph(350, 425, pGraph, true);
		DrawGraph(0, 300, retryStageGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 400, toSelectGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 500, toTitleGraph, true);
		break;
	case RETURN_TO_TITLE:
		DrawGraph(350, 525, pGraph, true);
		DrawGraph(0, 300, retryStageGraph, true);
		DrawGraph(0, 400, toSelectGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 500, toTitleGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}
	// デバックテキスト
	DrawFormatString(0, 0, GetColor(255, 255, 255), "ゲームオーバーシーン");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", menu_);
}