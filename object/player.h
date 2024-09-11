#pragma once
#include "DxLib.h"

struct PlayerStatus
{
	float X;	//���WX
	float Y;	//���WY
	float R;	//���a
	float MoveSpeed;//�ړ����x
	float FallSpeed;//�������x
	int O2; //�_�f
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
		640,	//���WX
		64,		//���WY
		64,		//���a
		5,		//�ړ����x
		1,		//�������x
		1000,	//�_�f
	};

	bool isInvincible_;//���G�t���O
	int invincibleTimer_;//���G�p�̃^�C�}�[
	int imagePlayer_;//player�p�̉摜
	int imageGauge_;//player�̃Q�[�W�摜
	float gauge_;
	float fullGauge_;
	float gaugeColor_;
};