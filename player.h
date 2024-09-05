#pragma once
#include "DxLib.h"

struct Status
{
	float X;	//座標X
	float Y;	//座標Y
	float R;	//半径
	float MoveSpeed;//移動速度
	float FallSpeed;//落下速度
};

class Player
{
public:
	void Initialize();
	void Update(char keys[256]);
	void Draw();

	void Move(char keys[256]);
	float GetScroll();

private:
	struct Status player = {
		640,//座標X
		64,	//座標Y
		64,	//半径
		5,	//移動速度
		1	//落下速度
	};

	float scroll;
};

