#pragma once
#include "Object.h"

/// <summary>
/// ファイアエフェクト
/// </summary>
class FireEffect : public Object
{
private: // メンバ変数
	// 回転度、拡縮
	double rotate;
	double scale;
	// 画像データ
	int fireEffect;

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