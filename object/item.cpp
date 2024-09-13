#include "item.h"

void Item::Initialize(ObjectStatus status)
{
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	//画像読み込み
	imageItem_ = LoadGraph("Resources/textures/item.png");
	// 音声データ
	seHandle = LoadSoundMem("Resources/sounds/se_o2.wav");
}

void Item::Finalize()
{
}

void Item::Update()
{
}

void Item::Draw(float scroll)
{
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawExtendGraph(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
		imageItem_, true);
}

//当たり判定
void Item::Collision()
{
	//当たったら消える
	status_.X = -50;
	// 効果音
	PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
}
