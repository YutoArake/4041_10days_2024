#include "item.h"

void Item::Initialize()
{

}

void Item::Update()
{
	
}

void Item::Draw()
{
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawBox(item.X - item.R, item.Y - item.R - scroll, item.X + item.R, item.Y + item.R - scroll,
		GetColor(0, 0, 200), true);


	DrawFormatString(3, 45, GetColor(0, 0, 0), "item_posX: %f", item.X);
	DrawFormatString(3, 60, GetColor(0, 0, 0), "item_posY: %f", item.Y);
}

void Item::SetScroll(float scroll)
{
	this->scroll = scroll;
}

ItemStatus Item::GetStatus()
{
	return item;
}

//当たり判定
void Item::Collision(int x1, int y1, int x2, int y2)
{
	if (x1 < item.X + item.R && item.X - item.R < x2) {
		if (y1 < item.Y + item.R && item.Y - item.R < y2) {
			//当たったら消える
			item.X = -50;
		}
	}
}
