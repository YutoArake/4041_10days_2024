#pragma once
#include "DxLib.h"

struct ItemStatus
{
	float X;		//���WX
	float Y;		//���WY
	float R;		//���a
	char Teg[64];	//�^�O
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
		640,	//���WX
		900,	//���WY
		20,		//���a
		"item"	//tag
	};

	float scroll;
};



