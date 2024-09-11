#include "GamePlayScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	image_back = LoadGraph("Resources/textures/back.png");//背景画像
	player->Initialize();
	stage.Initialize(GameSelectScene::stageNum_);
	playBgmHandle_ = LoadSoundMem("BGM/play_1.mp3"); //プレイBGM

	scroll = 0;
}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_ESCAPE] == true && oldkeys[KEY_INPUT_ESCAPE] == false)
	{
		// ステージセレクトへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	//BGMが鳴っていなかったら
	if (CheckSoundMem(playBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(playBgmHandle_, DX_PLAYTYPE_BACK);
	}

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		//BGM停止
		StopSoundMem(playBgmHandle_);
		return;
	}

	// オブジェクトの更新
	player->Update(keys, scroll);
	
	stage.Update();
	if (player->GetStatus().Y >= 2880 - player->GetStatus().R)
	{
		isClear = true;
	}

	// 当たり判定
	stage.ObjectCollision(player);
}

void GamePlayScene::Draw()
{
	DrawExtendGraph(0, 0 - scroll, 1280, 2880 - scroll, image_back, true);//背景のため、一番上に！
	stage.Draw(scroll);
	player->Draw(scroll);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}