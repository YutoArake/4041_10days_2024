#include "item.h"

void Item::Initialize(ObjectStatus status)
{
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;
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

	DrawBox(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
		GetColor(255, 0, 0), true);
}

//当たり判定
void Item::Collision()
{
	//当たったら消える
	status_.X = -50;
}
