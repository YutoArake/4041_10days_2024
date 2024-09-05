#pragma once
#include "DxLib.h"

struct Status
{
	float X;	//���WX
	float Y;	//���WY
	float R;	//���a
	float MoveSpeed;//�ړ����x
	float FallSpeed;//�������x
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
		640,//���WX
		64,	//���WY
		64,	//���a
		5,	//�ړ����x
		1	//�������x
	};

	float scroll;
};

