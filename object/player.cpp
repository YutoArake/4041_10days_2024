#include "player.h"

void Player::Initialize()
{
	isInvincible_ = false;
	fullGauge_ = player_.O2;

	imagePlayer_ = LoadGraph("Resources/textures/player.png");
	imageGauge_ = LoadGraph("Resources/textures/player_gauge.png");
}

void Player::Update(char keys[256], float& scroll)
{
	//酸素は常に減る
	player_.O2--;
	//0になったらストップ
	if (player_.O2 <= 0) {
		player_.O2 = 0;
	}

	//ゲージ
	float A = player_.X + player_.R - 4;
	float B = player_.X - player_.R + 4;

	gauge_ = B + ((B - A)/fullGauge_) * -player_.O2;
	gaugeColor_ = 255 * (player_.O2 / fullGauge_);

	//無敵時間
	int invincibleTime = 60;
	if (isInvincible_ == true) {
		invincibleTimer_++;

		if (invincibleTimer_ >= invincibleTime) {
			isInvincible_ = false;
			invincibleTimer_ = 0;
		}
	}

	//移動
	Move(keys, scroll);
}

void Player::Draw(float scroll)
{
	//ロケット
	//通常時
	if (isInvincible_ == false) {
		DrawExtendGraph(player_.X - player_.R, player_.Y - player_.R - scroll, player_.X + player_.R, player_.Y + player_.R - scroll,
			imagePlayer_, true);
	}
	//無敵時
	else {
		//点滅させる
		if (invincibleTimer_ % 5 == 0) {
			DrawExtendGraph(player_.X - player_.R, player_.Y - player_.R - scroll, player_.X + player_.R, player_.Y + player_.R - scroll,
				imagePlayer_, true);
		}
	}

	//ゲージ
	if(player_.O2 != 0)
	{
		DrawBox(
			player_.X - player_.R + 4,
			player_.Y - player_.R + 116 - scroll,
			gauge_,
			player_.Y + player_.R - scroll,
			GetColor(255 - gaugeColor_, gaugeColor_, 0), true);
	}
	
	//ゲージの枠
	DrawExtendGraph(player_.X - player_.R, player_.Y - player_.R - scroll, player_.X + player_.R, player_.Y + player_.R - scroll,
		imageGauge_, true);

	//デバック
}


//移動
void Player::Move(char keys[256], float& scroll)
{
#pragma region 踏ん張る
	if (keys[KEY_INPUT_UP] == true) {
		player_.Y -= player_.FallSpeed * 0.8;

		//スクロール加算
		if (player_.Y >= 300 && player_.Y <= 2220) {
			scroll -= player_.FallSpeed * 0.8;
		}

		//画面から出ないように移動制御
		if (player_.Y <= 0 + player_.R) {
			player_.Y = 0 + player_.R;
		}
	}
#pragma endregion 

#pragma region /*下にゆっくり*/
	if (keys[KEY_INPUT_DOWN] == true) {
		player_.Y += player_.FallSpeed * 5;

		//スクロール加算
		if (player_.Y >= 300 && player_.Y <= 2220) {
			scroll += player_.FallSpeed * 5;
		}

		//画面から出ないように移動制御
		if (player_.Y >= 2880 - player_.R) {
			player_.Y = 2880 - player_.R;
		}
	}

	//常にゆっくり落下
	player_.Y += player_.FallSpeed;

	//スクロール加算
	if (player_.Y >= 300 && player_.Y <= 2220) {
		scroll += player_.FallSpeed;
	}

	//画面から出ないように移動制御
	if (player_.Y >= 2880 - player_.R) {
		player_.Y = 2880 - player_.R;
	}

#pragma endregion 

#pragma region 左右移動
	if (keys[KEY_INPUT_LEFT] == true) {
		player_.X -= player_.MoveSpeed;

		//画面から出ないように移動制御
		if (player_.X <= 0 + player_.R) {
			player_.X = 0 + player_.R;
		}
	}

	if (keys[KEY_INPUT_RIGHT] == true) {
		player_.X += player_.MoveSpeed;

		//画面から出ないように移動制御
		if (player_.X >= 1280 - player_.R) {
			player_.X = 1280 - player_.R;
		}
	}
#pragma endregion 
}

//当たり判定
void Player::Collision(char tag)
{
	//当たったのが敵だった時
	if (tag == (char)'e' && isInvincible_ == false) {
		player_.O2 -= 500;
		//無敵時間スタート
		isInvincible_ = true;
	}

	//当たったのがアイテムだった時
	if (tag == (char)'i')
	{
		player_.O2 += 500;
		if(fullGauge_ <= player_.O2)
		{
			player_.O2 = fullGauge_;
		}
	}
}

PlayerStatus Player::GetStatus()
{
	return player_;
}
