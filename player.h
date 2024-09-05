#pragma once
#include "DxLib.h"

struct Status
{
	float X;	//座標X
	float Y;	//座標Y
	float R;	//半径
	float Speed;//速度
};

class Player
{
public:
	void Initialize();
	void Update(char keys[256]);
	void Draw();

	void Move(char keys[256]);
	int GetScroll();

private:
	struct Status player = {
		640,
		64,
		64,
		5
	};

	int scroll;
};

