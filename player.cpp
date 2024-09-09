#include "player.h"

void Player::Initialize()
{
	isInvincible = false;
}

void Player::Update(char keys[256])
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
	Move(keys);
}

void Player::Draw()
{
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawBox(player.X - player.R, player.Y - player.R - scroll, player.X + player.R, player.Y + player.R - scroll,
		GetColor(200, 200, 0), true);


	//デバック
	DrawFormatString(3, 0, GetColor(255, 255, 255), "posX: %f", player.X);
	DrawFormatString(3, 15, GetColor(255, 255, 255), "posY: %f", player.Y);
	DrawFormatString(3, 30, GetColor(255, 255, 255), "HP: %d", player.HP);
	DrawFormatString(3, 45, GetColor(255, 255, 255), "O2: %d", player.O2);
	DrawFormatString(3, 60, GetColor(255, 255, 255), "無敵: %d", isInvincible);
	DrawFormatString(3, 75, GetColor(255, 255, 255), "timer: %d", invincibleTimer);
}


//移動
void Player::Move(char keys[256])
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
		player.Y += player.FallSpeed*2;

		//スクロール加算
		if (player.Y >= 300 && player.Y <= 2220) {
			scroll += player.FallSpeed*2;
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

//"scroll"を渡す
float Player::GetScroll(){
	return scroll;
}

//当たり判定
void Player::Collision(int x1, int y1, int x2, int y2,char tag)
{
	if(x1< player.X + player.R && player.X - player.R < x2){
		if (y1 < player.Y + player.R && player.Y - player.R < y2) {
			//当たったのが敵だった時
			if(tag == (char)"enemy" && isInvincible == false){
				player.HP--;
				//無敵時間スタート
				isInvincible = true;
			}

			//当たったのがアイテムだった時
			if(tag == (char)"item")
			{
				player.O2 += 500;
			}
		}
	}
}

PlayerStatus Player::GetStatus()
{
	return player;
}
