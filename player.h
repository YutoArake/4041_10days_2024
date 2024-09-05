#pragma once
#include "DxLib.h"

struct Status
{
	float X;	//���WX
	float Y;	//���WY
	float R;	//���a
	float MoveSpeed;//�ړ����x
	float FallSpeed;//�������x
	int HP;
};

class Player
{
public:
	void Initialize();
	void Update(char keys[256]);
	void Draw();

	void Move(char keys[256]);
	float GetScroll();
	void Collision(int x1, int y1, int x2, int y2, char tag[64]);

private:
	struct Status player = {
		640,//���WX
		64,	//���WY
		64,	//���a
		5,	//�ړ����x
		1,	//�������x
		3,  //HP
	};

	float scroll;
};

