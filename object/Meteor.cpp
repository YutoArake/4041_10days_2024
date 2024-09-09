#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize(ObjectStatus status)
{
	// �X�e�[�^�X���
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	// �摜�f�[�^
	meteorGraph = LoadGraph("Resources/textures/meteor.png");
}

void Meteor::Finalize()
{
}

void Meteor::Update()
{
	status_.Y -= 1.0f;
}

void Meteor::Draw(float scroll)
{
	DrawGraph(status_.X - 32, status_.Y - 32 - scroll, meteorGraph, true);
}

void Meteor::Collision()
{
	//���������������
	status_.X = -50;
}
