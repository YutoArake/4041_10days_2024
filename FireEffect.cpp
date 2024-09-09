#include "FireEffect.h"
#include "DxLib.h"

void FireEffect::Initialize(ObjectStatus status)
{
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;

	// 回転度、拡縮
	rotate = 0.0f;
	scale = 1.0f;
	// 画像データ
	fireEffect = LoadGraph("Resources/textures/fireEffect.png");
}

void FireEffect::Finalize()
{
}

void FireEffect::Update()
{
	// 回転度、拡縮
	rotate -= 0.01f;
	scale -= 0.01f;
	status_.R -= 1.0f;

	if (scale < 0) {
		scale = 0;
	}

}

void FireEffect::Draw(float scroll)
{
	DrawRotaGraph(status_.X, status_.Y - scroll, scale, rotate, fireEffect, true, false);
}

void FireEffect::Collision()
{
}
