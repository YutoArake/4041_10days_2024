#pragma once
#include "DxLib.h"


struct Status
{
	float X;
	float Y;
	float R;
	float Speed;
};

class Enemy
{
public:

	void Initialize();
	void Update();
	void Move();
	void Draw();
	
private:

	struct Status enemy = {
		0,
		0,
		50,
		5
	};

};

