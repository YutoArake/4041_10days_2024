#include "GamePlayScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	// 画像データ
	image_back1 = LoadGraph("Resources/textures/back.png");//背景画像
	image_back2 = LoadGraph("Resources/textures/back2.png");//背景画像
	image_back3 = LoadGraph("Resources/textures/back3.png");//背景画像
	// 音声データ
	playBgmHandle_ = LoadSoundMem("BGM/play_1.mp3"); //プレイBGM

	// 初期化
	player->Initialize();
	stage.Initialize(GameSelectScene::stageNum_);

	scroll = 0;
}

void GamePlayScene::Finalize()
{
	stage.Finalize();
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_ESCAPE] == true && oldkeys[KEY_INPUT_ESCAPE] == false)
	{
		// ステージセレクトへ
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		//BGM停止
		StopSoundMem(playBgmHandle_);
		return;
	}

	if (player->GetStatus().O2 <= 0)
	{
		// ゲームオーバーシーンへ
		SceneManager::GetInstance()->ChangeScene("GAMEOVER");
		//BGM停止
		StopSoundMem(playBgmHandle_);
		return;
	}

	//BGMが鳴っていなかったら
	if (CheckSoundMem(playBgmHandle_) == 0)
	{
		//再生
		PlaySoundMem(playBgmHandle_, DX_PLAYTYPE_BACK);
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
	//背景のため、一番上に！
	if (GameSelectScene::stageNum_ == 1) DrawExtendGraph(0, 0 - scroll, 1280, 2880 - scroll, image_back1, true);
	if (GameSelectScene::stageNum_ == 2) DrawExtendGraph(0, 0 - scroll, 1280, 2880 - scroll, image_back2, true);
	if (GameSelectScene::stageNum_ == 3) DrawExtendGraph(0, 0 - scroll, 1280, 2880 - scroll, image_back3, true);

	stage.Draw(scroll);
	player->Draw(scroll);
}