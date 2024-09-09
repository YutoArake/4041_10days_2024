#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	image_123 = LoadGraph("back.png");//”wŒi‰æ‘œ
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
		// ƒQ[ƒ€ƒvƒŒƒCƒV[ƒ“‚Ö
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}

	player->Update(keys);
	item->Update();

	//ƒXƒNƒ[ƒ‹À•W‚ÌŽó‚¯“n‚µ
	scroll = player->GetScroll();
	item->SetScroll(scroll);

	//“–‚½‚è”»’è
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
	DrawExtendGraph(0, 0-scroll, 1280, 2880-scroll, image_123, true);//”wŒi‚Ì‚½‚ßAˆê”Ôã‚ÉI
	//DrawBox(860, 0, 1280, 960, GetColor(0, 0, 0), true);

	player->Draw();
	item->Draw();
}