#pragma once
#include "DxLib.h"

struct ItemStatus
{
	float X;		//���WX
	float Y;		//���WY
	float R;		//���a
	char Teg;	//�^�O
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
		640,	//���WX
		900,	//���WY
		20,		//���a
		(char)"item"	//tag
	};

	float scroll;
};



