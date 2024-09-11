#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize(ObjectStatus status)
{
	// ステータス代入
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	// 沸き場所
	// 上
	if (status_.Y < 0) {
		// 左
		if (status_.X < 32) pos = Posision::LeftTop;
		// 右
		else if (status_.X > 1248) pos = Posision::RightTop;
	}
	// 下
	else if (status_.Y >= 1000) {
		pos = Posision::Under;
		// 左
		if (status_.X < 32) pos = Posision::LeftUnder;
		// 右
		else if (status_.X > 1248) pos = Posision::RightUnder;
	}
	// タイマー
	timer = 10;

	// 画像データ
	meteorGraph = LoadGraph("Resources/textures/meteor.png");
	// 音声データ
	seHandle = LoadSoundMem("Resources/sounds/se_meteor.mp3");
}

void Meteor::Finalize()
{
}

void Meteor::Update()
{
	switch (pos)
	{
	case Meteor::Posision::LeftTop:
		status_.Y += 3.0f;
		status_.X += 3.0f;
		break;
	case Meteor::Posision::RightTop:
		status_.Y += 3.0f;
		status_.X -= 3.0f;
		break;
	case Meteor::Posision::Under:
		status_.Y -= 1.0f;
		break;
	case Meteor::Posision::LeftUnder:
		status_.Y -= 1.0f;
		status_.X += 1.0f;
		break;
	case Meteor::Posision::RightUnder:
		status_.Y -= 1.0f;
		status_.X -= 1.0f;
		break;
	}

	// タイマー
	timer--;

	// 全エフェクトの更新
	for (auto& effect : effects) { effect->Update(); }

	if (timer <= 0) {
		ObjectStatus status;
		status.X = status_.X;
		status.Y = status_.Y;
		status.R = status_.R;
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
	status_.X = -5000;
	// 効果音
	PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
}
