#include "Enemy.h"


void Enemy::Initialize()
{

}

void Enemy::Update()
{

}

void Enemy::Move()
{

}

void Enemy::Draw()
{
	DrawBox(enemy.X - enemy.R, enemy.Y - enemy.R, enemy.X + enemy.R, enemy.Y + enemy.R,
		GetColor(255, 0, 0), true);
}
