#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize(ObjectStatus status)
{
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	// タイマー
	timer = 10;

	// 画像データ
	meteorGraph = LoadGraph("Resources/textures/meteor.png");
}

void Meteor::Finalize()
{
}

void Meteor::Update()
{
	status_.Y -= 1.0f;
	timer--;

	// 全エフェクトの更新
	for (auto& effect : effects) { effect->Update(); }

	if (timer <= 0) {
		ObjectStatus status;
		status.X = status_.X;
		status.Y = status_.Y;
		status.R = 32;
		// 宣言、生成
		std::unique_ptr<FireEffect> effect;
		effect = std::make_unique<FireEffect>();
		effect->Initialize(status);
		// コンテナにプッシュ
		effects.push_back(std::move(effect));

		timer = 10;
	}
}

void Meteor::Draw(float scroll)
{
	// 全エフェクトの更新
	for (auto& effect : effects) { effect->Draw(scroll); }
	DrawGraph(status_.X - 32, status_.Y - 32 - scroll, meteorGraph, true);
}

void Meteor::Collision()
{
	//当たったら消える
	status_.X = -50;
}
