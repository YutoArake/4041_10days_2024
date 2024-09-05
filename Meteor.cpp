#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize()
{
	// ���W
	pos.x = 600;
	pos.y = 1000.0f;

	// �摜�f�[�^
	meteorGraph = LoadGraph("Resources/textures/meteor.png");
}

void Meteor::Finalize()
{
}

void Meteor::Update()
{
	pos.y -= 1.0f;
}

void Meteor::Draw()
{
	DrawGraph(pos.x - 32, pos.y - 32, meteorGraph, true);
}