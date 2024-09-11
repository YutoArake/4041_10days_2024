#include "Enemy.h"


void Enemy::Initialize(ObjectStatus status)
{
	image_enemy = LoadGraph("Resources/textures/enemy_1.png");
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	speed_ = 5;
	saveSpeed_ = speed_;
	isMove_ = true;
	randSpeed_ = 1;//乱数用

}

void Enemy::Finalize()
{
}

void Enemy::Update()
{
	Move();
}

void Enemy::Draw(float scroll)
{
	DrawExtendGraph(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
		image_enemy, true);
}

//当たり判定
void Enemy::Collision()
{
	////当たったら消える
	//status_.X = -50;
}

void Enemy::Move()
{
#pragma region 
#pragma endregion

#pragma region /*左右移動一定*/
	/*status_.X = status_.X + speed;

	if (status_.X >= 1280)
	{
		speed = -speed;
	}
	else if (status_.X <= 0)
	{
		speed = -speed;
	}*/
#pragma endregion

#pragma region /*左右移動一定で止まる*/
	/*int stopTime = 30;
	if (isMove == true) {
		status_.X = status_.X + speed;
	}
	

	if (status_.X >= 1280)
	{
		speed = -saveSpeed;
		isMove = false;
		if(isMove == false)
		{
			stopTimer++;
			if(stopTimer >= stopTime)
			{
				stopTimer = 0;
				isMove = true;
			}
		}
	}
	else if (status_.X <= 0)
	{
		speed = saveSpeed;
		isMove = false;
		if (isMove == false)
		{
			stopTimer++;
			if (stopTimer >= stopTime)
			{
				stopTimer = 0;
				isMove = true;
			}
		}
	}*/

#pragma endregion

#pragma region 左右速度変動
	int randTime = 30;
	
	randTimer_++;
	if(randTimer_ >= randTime)
	{
		randSpeed_ = GetRand(30);
		randTimer_ = 0;
	}

	status_.X = status_.X + speed_ * (randSpeed_ * 0.1);
	
	if (status_.X >= 1280)
	{
		speed_ = -saveSpeed_;
	}
	else if (status_.X <= 0)
	{
		speed_ = saveSpeed_;
	}
#pragma endregion
	
#pragma region /*上にくる*/
	
#pragma endregion
}
