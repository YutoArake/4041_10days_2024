#pragma once
#include "DxLib.h"

struct Status
{
	float X;	//ç¿ïWX
	float Y;	//ç¿ïWY
	float R;	//îºåa
	float Speed;//ë¨ìx
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

