#include "player.h"

void Player::Initialize()
{
	isInvincible = false;
	image_player = LoadGraph("Resources/textures/player.png");
}

void Player::Update(char keys[256], float& scroll)
{
	//酸素は常に減る
	player.O2--;

	//無敵時間
	int invincibleTime = 60;
	if (isInvincible == true) {
		invincibleTimer++;

		if (invincibleTimer >= invincibleTime) {
			isInvincible = false;
			invincibleTimer = 0;
		}
	}

	//移動
	Move(keys, scroll);
}

void Player::Draw(float scroll)
{
	//通常時
	if (isInvincible == false) {
		/*DrawBox(player.X - player.R, player.Y - player.R - scroll, player.X + player.R, player.Y + player.R - scroll,
			GetColor(0, 255, 0), true);*/

		DrawExtendGraph(player.X - player.R, player.Y - player.R - scroll, player.X + player.R, player.Y + player.R - scroll,
			image_player, true);
	}
	//無敵時
	else 
		//点滅させる
		if (invincibleTimer % 5 == 0) {
			DrawExtendGraph(player.X - player.R, player.Y - player.R - scroll, player.X + player.R, player.Y + player.R - scroll,
				image_player, true);
		}
	}

	//デバック
	DrawFormatString(3, 0, GetColor(255, 255, 255), "posX: %f", player.X);
	DrawFormatString(3, 15, GetColor(255, 255, 255), "posY: %f", player.Y);
	DrawFormatString(3, 30, GetColor(255, 255, 255), "HP: %d", player.HP);
	DrawFormatString(3, 45, GetColor(255, 255, 255), "O2: %d", player.O2);
	DrawFormatString(3, 60, GetColor(255, 255, 255), "無敵: %d", isInvincible);
	DrawFormatString(3, 75, GetColor(255, 255, 255), "timer: %d", invincibleTimer);
}


//移動
void Player::Move(char keys[256], float& scroll)
{
#pragma region 踏ん張る
	if (keys[KEY_INPUT_UP] == true) {
		player.Y -= player.FallSpeed * 0.8;

		//スクロール加算
		if (player.Y >= 300 && player.Y <= 2220) {
			scroll -= player.FallSpeed * 0.8;
		}

		//画面から出ないように移動制御
		if (player.Y <= 0 + player.R) {
			player.Y = 0 + player.R;
		}
	}
#pragma endregion 

#pragma region 下にゆっくり
	if (keys[KEY_INPUT_DOWN] == true) {
		player.Y += player.FallSpeed * 2;

		//スクロール加算
		if (player.Y >= 300 && player.Y <= 2220) {
			scroll += player.FallSpeed * 2;
		}

		//画面から出ないように移動制御
		if (player.Y >= 2880 - player.R) {
			player.Y = 2880 - player.R;
		}
	}

	//常にゆっくり落下
	player.Y += player.FallSpeed;

	//スクロール加算
	if (player.Y >= 300 && player.Y <= 2220) {
		scroll += player.FallSpeed;
	}

	//画面から出ないように移動制御
	if (player.Y >= 2880 - player.R) {
		player.Y = 2880 - player.R;
	}

#pragma endregion 

#pragma region 左右移動
	if (keys[KEY_INPUT_LEFT] == true) {
		player.X -= player.MoveSpeed;

		//画面から出ないように移動制御
		if (player.X <= 0 + player.R) {
			player.X = 0 + player.R;
		}
	}

	if (keys[KEY_INPUT_RIGHT] == true) {
		player.X += player.MoveSpeed;

		//画面から出ないように移動制御
		if (player.X >= 1280 - player.R) {
			player.X = 1280 - player.R;
		}
	}
#pragma endregion 
}

//当たり判定
void Player::Collision(char tag)
{
	//当たったのが敵だった時
	if (tag == (char)'e' && isInvincible == false) {
		player.HP--;
		//無敵時間スタート
		isInvincible = true;
	}

	//当たったのがアイテムだった時
	if (tag == (char)'i')
	{
		player.O2 += 500;

	}
}

PlayerStatus Player::GetStatus()
{
	return player;
}
