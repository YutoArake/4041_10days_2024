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
}

void Item::SetScroll(float scroll)
{
	this->scroll = scroll;
}

ItemStatus Item::GetStatus()
{
	return item;
}

//“–‚½‚è”»’è
void Item::Collision(int x1, int y1, int x2, int y2)
{
	if (x1 < item.X + item.R && item.X - item.R < x2) {
		if (y1 < item.Y + item.R && item.Y - item.R < y2) {
			//“–‚½‚Á‚½‚çÁ‚¦‚é
			item.X = -50;
		}
	}
}
