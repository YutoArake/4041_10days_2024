#pragma once
#include "Vector2.h"

/// <summary>
/// オブジェクトクラス(親クラス)
/// </summary>
class Object
{
protected: // メンバ変数
	// 座標
	Vector2 pos;

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	///  描画
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize() = 0;
};