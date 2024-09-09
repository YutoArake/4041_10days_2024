#pragma once
#include "DxLib.h"

struct PlayerStatus
{
	float X;	//���WX
	float Y;	//���WY
	float R;	//���a
	float MoveSpeed;//�ړ����x
	float FallSpeed;//�������x
	int HP;	//���C�t
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
	struct PlayerStatus player = {
		640,	//���WX
		64,		//���WY
		64,		//���a
		5,		//�ړ����x
		1,		//�������x
		3,		//HP
		1000,	//�_�f
	};

	bool isInvincible;//���G�t���O
	int invincibleTimer;//���G�p�̃^�C�}�[
	int image_player;//player�p�̉摜
};