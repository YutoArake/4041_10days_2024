#include "Enemy.h"


void Enemy::Initialize(ObjectStatus status)
{
	// �X�e�[�^�X���
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	speed = 5;
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
}

//�����蔻��
void Enemy::Collision()
{
	//���������������
	status_.X = -50;
}

void Enemy::Move()
{
	status_.X = status_.X + speed;

	if (status_.X >= 1280)
	{
		speed = -speed;
	}
	else if (status_.X <= 0)
	{
		speed = -speed;
	}
}