#include "player.h"

void Player::Initialize()
{

}

void Player::Update(char keys[256])
{
	//�ړ�
	Move(keys);
}

void Player::Draw()
{
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawBox(player.X - player.R, player.Y - player.R - scroll, player.X + player.R, player.Y + player.R - scroll,
		GetColor(200, 200, 0), true);


	//�f�o�b�N
	DrawFormatString(3, 0, GetColor(0, 0, 0), "posX: %f", player.X);
	DrawFormatString(3, 15, GetColor(0, 0, 0), "posY: %f", player.Y);
	DrawFormatString(3, 30, GetColor(0, 0, 0), "HP: %d", player.HP);
}


//�ړ�
void Player::Move(char keys[256])
{
#pragma region ���񒣂�
	if (keys[KEY_INPUT_UP] == true) {
		player.Y -= player.FallSpeed * 0.8;

		//�X�N���[�����Z
		if (player.Y >= 300 && player.Y <= 2220) {
			scroll -= player.FallSpeed * 0.8;
		}

		//��ʂ���o�Ȃ��悤�Ɉړ�����
		if (player.Y <= 0 + player.R) {
			player.Y = 0 + player.R;
		}
	}
#pragma endregion 

#pragma region ���ɂ������
	if (keys[KEY_INPUT_DOWN] == true) {
		player.Y += player.FallSpeed*2;

		//�X�N���[�����Z
		if (player.Y >= 300 && player.Y <= 2220) {
			scroll += player.FallSpeed*2;
		}

		//��ʂ���o�Ȃ��悤�Ɉړ�����
		if (player.Y >= 2880 - player.R) {
			player.Y = 2880 - player.R;
		}
	}

	//��ɂ�����藎��
	player.Y += player.FallSpeed;

	//�X�N���[�����Z
	if (player.Y >= 300 && player.Y <= 2220) {
		scroll += player.FallSpeed;
	}

	//��ʂ���o�Ȃ��悤�Ɉړ�����
	if (player.Y >= 2880 - player.R) {
		player.Y = 2880 - player.R;
	}

#pragma endregion 
	
#pragma region ���E�ړ�
	if (keys[KEY_INPUT_LEFT] == true) {
		player.X -= player.MoveSpeed;

		//��ʂ���o�Ȃ��悤�Ɉړ�����
		if (player.X <= 0 + player.R) {
			player.X = 0 + player.R;
		}
	}

	if (keys[KEY_INPUT_RIGHT] == true) {
		player.X += player.MoveSpeed;

		//��ʂ���o�Ȃ��悤�Ɉړ�����
		if (player.X >= 1280 - player.R) {
			player.X = 1280 - player.R;
		}
	}
#pragma endregion 
}

//"scroll"��n��
float Player::GetScroll(){
	return scroll;
}

//�����蔻��
void Player::Collision(int x1, int y1, int x2, int y2,char tag)
{
	if(x1< player.X + player.R && player.X - player.R < x2){
		if (y1 < player.Y + player.R && player.Y - player.R < y2) {
			//���������̂��G��������
			if(tag == (char)"enemy")
			{

			}

			//���������̂��A�C�e����������
			if(tag == (char)"item")
			{
				player.HP += 1;
			}
		}
	}
}

PlayerStatus Player::GetStatus()
{
	return player;
}
