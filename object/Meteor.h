#pragma once
#include "Object.h"
#include "FireEffect.h"
#include <iostream>

/// <summary>
/// メテオ(子クラス)
/// </summary>
class Meteor : public Object
{
	// 列挙
	enum class Posision {
		LeftTop,
		RightTop,
		Under,
		LeftUnder,
		RightUnder
	};

private: // メンバ変数
	// 画像データ
	int meteorGraph;
	// 音声データ
	int seHandle;

	// 沸き場所で挙動を変えるための変数
	Posision pos;

	// エフェクト用タイマー
	int timer;
	// エフェクトコンテナ
	std::vector<std::unique_ptr<FireEffect>> effects;

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(ObjectStatus status) override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update() override;

	/// <summary>
	///  描画
	/// </summary>
	void Draw(float scroll) override;

	// 当たり判定
	void Collision() override;
};