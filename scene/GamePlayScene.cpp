#include "GamePlayScene.h"
#include "SceneManager.h"

void GamePlayScene::Initialize()
{
	image_123 = LoadGraph("back.png");//�w�i�摜
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
		// �Q�[���v���C�V�[����
		SceneManager::GetInstance()->ChangeScene("CLEAR");
		return;
	}

	player->Update(keys);
	item->Update();

	//�X�N���[�����W�̎󂯓n��
	scroll = player->GetScroll();
	item->SetScroll(scroll);

	//�����蔻��
	
	x = item->GetStatus().X;
	y = item->GetStatus().Y;
	r = item->GetStatus().R;
	tag = (char)"item";

	player->Collision(x - r, y - r, x + r, y + r, (char)tag);
	item->Collision(
		player->GetStatus().X - player->GetStatus().R,
		player->GetStatus().Y - player->GetStatus().R,
		player->GetStatus().X + player->GetStatus().R,
		player->GetStatus().Y + player->GetStatus().R);

}

void GamePlayScene::Draw()
{
	DrawGraph(0, -scroll, image_123, true);//�w�i�̂��߁A��ԏ�ɁI
	
	player->Draw();
	item->Draw();

	DrawFormatString(3, 75, GetColor(0, 0, 0), "x: %f", x);
	DrawFormatString(3, 90, GetColor(0, 0, 0), "y: %f", y);
	
}