#pragma once
#include "DxLib.h"

struct ItemStatus
{
	float X;		//座標X
	float Y;		//座標Y
	float R;		//半径
	char Teg;	//タグ
};

class Item
{
public:
	void Initialize();
	void Update();
	void Draw();

	void Collision(int x1, int y1, int x2, int y2);
	ItemStatus GetStatus();

	void SetScroll(float scroll);

private:
	struct ItemStatus item = {
		640,	//座標X
		900,	//座標Y
		20,		//半径
		(char)"item"	//tag
	};

	float scroll;
};



