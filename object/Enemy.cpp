#include "Enemy.h"


void Enemy::Initialize(ObjectStatus status)
{
	imageEnemy1_ = LoadGraph("Resources/textures/enemy_1.png");
	imageEnemy2_ = LoadGraph("Resources/textures/enemy_2.png");
	imageEnemy3_ = LoadGraph("Resources/textures/enemy_3.png");
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.type = status.type;
	status_.Tag = status.Tag;

	speed_ = 5;
	saveSpeed_ = speed_;
	isMove_ = true;
	randSpeed_ = 1;//乱数用

	stopTime_ = 30;
	randTime_ = 30;
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
	

	switch (status_.type)
	{
	case 1:
		DrawExtendGraph(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
			imageEnemy1_, true);
		break;

	case 2:
		DrawExtendGraph(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
			imageEnemy2_, true);
		break;

	case 3:
		DrawExtendGraph(status_.X - status_.R, status_.Y - status_.R - scroll, status_.X + status_.R, status_.Y + status_.R - scroll,
			imageEnemy3_, true);
		break;
	}

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

	switch (status_.type)
	{
	case 1:
#pragma region
		status_.X = status_.X + speed_;

		if (status_.X >= 1280)
		{
			speed_ = -speed_;
		}
		else if (status_.X <= 0)
		{
			speed_ = -speed_;
		}
#pragma endregion
		break;
	case 2:
#pragma region
		if (isMove_ == true) {
			status_.X = status_.X + speed_;
		}


		if (status_.X >= 1280)
		{
			speed_ = -saveSpeed_;
			isMove_ = false;
			if (isMove_ == false)
			{
				stopTimer_++;
				if (stopTimer_ >= stopTime_)
				{
					stopTimer_ = 0;
					isMove_ = true;
				}
			}
		}
		else if (status_.X <= 0)
		{
			speed_ = saveSpeed_;
			isMove_ = false;
			if (isMove_ == false)
			{
				stopTimer_++;
				if (stopTimer_ >= stopTime_)
				{
					stopTimer_ = 0;
					isMove_ = true;
				}
			}
		}

#pragma endregion

		break;
	case 3:
#pragma region
		randTimer_++;
		if (randTimer_ >= randTime_)
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
		break;
	}
}
