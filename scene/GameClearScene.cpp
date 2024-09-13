#include "GameClearScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GameClearScene::Initialize()
{
	// メニュー
	menu_ = NEXT_STAGE;
	isFainalStage = false;
	if (GameSelectScene::stageNum_ == GameSelectScene::STAGE_MAX_NUM) {
		menu_ = RETURN_TO_STAGESELECT;
		isFainalStage = true;
	}

	// 画像データ
	bgGraph = LoadGraph("Resources/textures/clear.png");
	pGraph = LoadGraph("Resources/textures/yajirushi.png");
	nextStageGraph = LoadGraph("Resources/textures/nextStage.png");
	toSelectGraph = LoadGraph("Resources/textures/selectScene.png");
	toTitleGraph = LoadGraph("Resources/textures/titleScene.png");

	// BGMデータ
	clearBgmHandle_ = LoadSoundMem("BGM/gameClear.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");

	alpha_ = 255;
	add_ = -5;
}

void GameClearScene::Finalize()
{
}

void GameClearScene::Update(char keys[256] , char oldkeys[256])
{
	//BGMが鳴っていなかったら
	if (CheckSoundMem(clearBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(clearBgmHandle_, DX_PLAYTYPE_BACK);
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
		//BGMが鳴っていなかったら
		if (CheckSoundMem(clearBgmHandle_) == 0)
		{
			//再生
			PlaySoundMem(clearBgmHandle_, DX_PLAYTYPE_BACK);
		}
		if (menu_ == NEXT_STAGE) {
			//// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// ゲームプレイシーンへ
			GameSelectScene::stageNum_++;
			SceneManager::GetInstance()->ChangeScene("PLAY");
			//BGM停止
			StopSoundMem(clearBgmHandle_);
			return;
		}
		else if (menu_ == RETURN_TO_STAGESELECT) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// セレクトシーンへ
			SceneManager::GetInstance()->ChangeScene("SELECT");
			//BGM停止
			StopSoundMem(clearBgmHandle_);
			return;
		}
		else if (menu_ == RETURN_TO_TITLE) {
			// 効果音
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// タイトルへ
			SceneManager::GetInstance()->ChangeScene("TITLE");
			//BGM停止
			StopSoundMem(clearBgmHandle_);
			return;
		}
	}
}

void GameClearScene::Draw()
{
	DrawGraph(0, 0, bgGraph, true);
	// 選択
	switch (menu_)
	{
	case NEXT_STAGE:	
		DrawGraph(350, 325, pGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		if (!isFainalStage) DrawGraph(0, 300, nextStageGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 400, toSelectGraph, true);
		DrawGraph(0, 500, toTitleGraph, true);
		break;
	case RETURN_TO_STAGESELECT:
		DrawGraph(350, 425, pGraph, true);
		if (!isFainalStage) DrawGraph(0, 300, nextStageGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 400, toSelectGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 500, toTitleGraph, true);
		break;
	case RETURN_TO_TITLE:
		DrawGraph(350, 525, pGraph, true);
		if (!isFainalStage) DrawGraph(0, 300, nextStageGraph, true);
		DrawGraph(0, 400, toSelectGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 500, toTitleGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}
}