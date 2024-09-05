#include "player.h"

void Player::Initialize()
{

}

void Player::Update(char keys[256])
{
	//ˆÚ“®
	Move(keys);

	DrawFormatString(0, 0, GetColor(255, 255, 255), "PLposX: %d", player.X);
	DrawFormatString(0, 12, GetColor(255, 255, 255), "PLposY: %d", player.Y);
}

void Player::Draw()
{
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawBox(player.X - player.R, player.Y - player.R, player.X + player.R, player.Y + player.R,
		GetColor(255, 0, 0), true);

}


//ˆÚ“®
void Player::Move(char keys[256])
{
	if (keys[KEY_INPUT_UP] == true) {
		player.Y -= player.Speed;
	}

	if (keys[KEY_INPUT_DOWN] == true) {
		player.Y += player.Speed;
	}

	if (keys[KEY_INPUT_LEFT] == true) {
		player.X -= player.Speed;
	}

	if (keys[KEY_INPUT_RIGHT] == true) {
		player.X += player.Speed;
	}

}
