#pragma once
#include "DxLib.h"

struct PlayerStatus
{
	float X;	//座標X
	float Y;	//座標Y
	float R;	//半径
	float MoveSpeed;//移動速度
	float FallSpeed;//落下速度
	int O2; //酸素
};

class Player
{
public:
	void Initialize();
	void Update(char keys[256], float& scroll);
	void Draw(float scroll);

	void Move(char keys[256], float& scroll);
	void Collision(char tag);
	PlayerStatus GetStatus();

private:
	struct PlayerStatus player_ = {
		640,	//座標X
		64,		//座標Y
		64,		//半径
		5,		//移動速度
		1,		//落下速度
		1000,	//酸素
	};

	bool isInvincible_;//無敵フラグ
	int invincibleTimer_;//無敵用のタイマー
	int imagePlayer_;//player用の画像
	int imageGauge_;//playerのゲージ画像
	float gauge_;
	float fullGauge_;
	float gaugeColor_;
};