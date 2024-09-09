#pragma once
#include <vector>

/// <summary>
/// オブジェクトステータスの構造体
/// </summary>
struct ObjectStatus
{
	float X;		//座標X
	float Y;		//座標Y
	float R;		//半径
	char Tag;		//タグ
};

/// <summary>
/// オブジェクトクラス(親クラス)
/// </summary>
class Object
{
protected: // メンバ変数
	// ステータス
	ObjectStatus status_;

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize(ObjectStatus status) = 0;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	///  描画
	/// </summary>
	virtual void Draw(float scroll) = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize() = 0;

	// 当たり判定
	virtual void Collision() = 0;

	// ゲッター
	ObjectStatus GetStatus() { return status_; }
};