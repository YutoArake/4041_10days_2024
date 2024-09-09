#include "GamePlayScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	enemy_.Initialize();
	image_back = LoadGraph("Resources/textures/back.png");//背景画像
	player->Initialize();
	stage.Initialize(GameSelectScene::stageNum_);

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

	if (isClear) {
		// ゲームクリアシーンへ
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}

	// オブジェクトの更新
	player->Update(keys, scroll);
	enemy_.Move();
	stage.Update();

	// 当たり判定
	stage.ObjectCollision(player);
}

void GamePlayScene::Draw()
{
	DrawExtendGraph(0, 0 - scroll, 1280, 2880 - scroll, image_back, true);//背景のため、一番上に！
	stage.Draw(scroll);
	//enemy_.Draw();
	player->Draw(scroll);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
}