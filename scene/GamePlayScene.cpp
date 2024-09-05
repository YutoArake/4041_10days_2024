#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	image_123 = LoadGraph("123.png");//”wŒi‰æ‘œ
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
	scroll = player->GetScroll();
}

void GamePlayScene::Draw()
{
	DrawGraph(0, -scroll, image_123, true);//”wŒi‚Ì‚½‚ßAˆê”Ôã‚ÉI
	player->Draw();

}