#include "player.h"

void Player::Initialize()
{

}

void Player::Update(char keys[256])
{
	//移動
	Move(keys);
}

void Player::Draw()
{
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawBox(player.X - player.R, player.Y - player.R - scroll, player.X + player.R, player.Y + player.R - scroll,
		GetColor(200, 200, 0), true);

	DrawFormatString(0, 0, GetColor(0, 0, 0), "PLposX: %f", player.X);
	DrawFormatString(0, 12, GetColor(0, 0, 0), "PLposY: %f", player.Y);

}


//移動
void Player::Move(char keys[256])
{
	if (keys[KEY_INPUT_UP] == true) {
		player.Y -= player.Speed;

		//スクロール加算
		if (player.Y >= 300 && player.Y <= 2220) {
			scroll -= player.Speed;
		}

		//画面から出ないように移動制御
		if (player.Y <= 0 + player.R) {
			player.Y = 0 + player.R;
		}
	}

	if (keys[KEY_INPUT_DOWN] == true) {
		player.Y += player.Speed;

		//スクロール加算
		if(player.Y >= 300 && player.Y <= 2220){
			scroll += player.Speed;
		}

		//画面から出ないように移動制御
		if (player.Y >= 2880 - player.R) {
			player.Y = 2880 - player.R;
		}
	}

	if (keys[KEY_INPUT_LEFT] == true) {
		player.X -= player.Speed;

		//画面から出ないように移動制御
		if (player.X <= 0 + player.R) {
			player.X = 0 + player.R;
		}
	}

	if (keys[KEY_INPUT_RIGHT] == true) {
		player.X += player.Speed;

		//画面から出ないように移動制御
		if (player.X >= 1280 - player.R) {
			player.X = 1280 - player.R;
		}
	}

}

//"scroll"を渡す
float Player::GetScroll(){
	return scroll;
}
