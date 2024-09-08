#pragma once
#include "DxLib.h"

struct ItemStatus
{
	float X;		//座標X
	float Y;		//座標Y
	float R;		//半径
	char Teg[64];	//タグ
};

class Item
{
public:
	void Initialize();
	void Update();
	void Draw();

	ItemStatus GetStatus();

	void SetScroll(float scroll);

private:
	struct ItemStatus item = {
		640,	//座標X
		900,	//座標Y
		20,		//半径
		"item"	//tag
	};

	float scroll;
};



