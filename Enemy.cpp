#include "Enemy.h"


void Enemy::Initialize()
{

}

void Enemy::Update()
{

}

void Enemy::Move()
{
	enemy.X = enemy.X + enemy.Speed;

	if (enemy.X >= enemy.max_WIDTH)
	{
		enemy.Speed = -enemy.Speed;
	}
	else if (enemy.X <= -enemy.min_WIDTH)
	{
		enemy.Speed = -enemy.Speed;
	}
}

void Enemy::Draw()
{
	DrawBox(enemy.X - enemy.R, enemy.Y - enemy.R, enemy.X + enemy.R, enemy.Y + enemy.R,
		GetColor(255, 0, 0), true);

}
