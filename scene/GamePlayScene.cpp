#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	image_123 = LoadGraph("back.png");//背景画像
	player->Initialize();
	item->Initialize();
}

void GamePlayScene::Finalize()
{
}

void GamePlayScene::Update(char keys[256], char oldkeys[256])
{
	if (keys[KEY_INPUT_ESCAPE] == true &&
		oldkeys[KEY_INPUT_ESCAPE] == false) {
		SceneManager::GetInstance()->ChangeScene("SELECT");
		return;
	}

	if (isClear) {
		// ゲームプレイシーンへ
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
	DrawExtendGraph(0, 0-scroll, 1280, 2880-scroll, image_123, true);//背景のため、一番上に！
	//DrawBox(860, 0, 1280, 960, GetColor(0, 0, 0), true);

	player->Draw();
	item->Draw();
}