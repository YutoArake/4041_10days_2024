#pragma once
#include "DxLib.h"


struct Status
{
	float X;
	float Y;
	float R;
	float Speed;
	float min_WIDTH; //�G�̍ŏ����˔͈�
	float max_WIDTH; //�G�̍ő唽�˔͈�
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
		10,
		1,
		1000
	};

	bool flag = true;

};

