#include "GamePlayScene.h"
#include "GameSelectScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	enemy_.Initialize();
	image_back = LoadGraph("back.png");//背景画像
	player->Initialize();
	item->Initialize();
	stage.Initialize(GameSelectScene::stageNum_);
}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	enemy_.Move();

	if (keys[KEY_INPUT_ESCAPE] == true &&
		oldkeys[KEY_INPUT_ESCAPE] == false) {
	stage.Update();

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

	player->Update(keys);
	item->Update();

	//スクロール座標の受け渡し
	scroll = player->GetScroll();
	item->SetScroll(scroll);

	//当たり判定
	player->Collision(
		item->GetStatus().X - item->GetStatus().R,
		item->GetStatus().Y - item->GetStatus().R,
		item->GetStatus().X + item->GetStatus().R,
		item->GetStatus().Y + item->GetStatus().R,
		(char)item->GetStatus().Teg);


	item->Collision(
		player->GetStatus().X - player->GetStatus().R,
		player->GetStatus().Y - player->GetStatus().R,
		player->GetStatus().X + player->GetStatus().R,
		player->GetStatus().Y + player->GetStatus().R);

}

void GamePlayScene::Draw()
{
	DrawExtendGraph(0, 0 - scroll, 1280, 2880 - scroll, image_back, true);//背景のため、一番上に！
	

	player->Draw();
	enemy_.Draw();
	item->Draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "play");
	stage.Draw();
}