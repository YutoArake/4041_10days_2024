#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize(ObjectParam param)
{
	// ���W����
	pos.x = param.x;
	pos.y = param.y;

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