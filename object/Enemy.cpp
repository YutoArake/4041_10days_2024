#include "Enemy.h"


void Enemy::Initialize(ObjectStatus status)
{
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	speed = 5;
	saveSpeed = speed;
	isMove = true;
	randSpeed = 1;
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
	//DrawBox(0, 0, 10, 10, GetColor(255, 0, 0), true);

	DrawBox(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
		GetColor(255, 0, 0), true);

	DrawFormatString(3, 90, GetColor(255, 255, 255), "isMove: %d", isMove);
}

//当たり判定
void Enemy::Collision()
{
	//当たったら消える
	status_.X = -50;
}

void Enemy::Move()
{
#pragma region 
#pragma endregion

#pragma region 左右移動一定
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

#pragma region 左右移動一定で止まる
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
	
	randTimer++;
	if(randTimer >= randTime)
	{
		randSpeed = GetRand(30);
		randTimer = 0;
	}

	status_.X = status_.X + speed * (randSpeed * 0.1);
	
	if (status_.X >= 1280)
	{
		speed = -saveSpeed;
	}
	else if (status_.X <= 0)
	{
		speed = saveSpeed;
	}
#pragma endregion
	
}