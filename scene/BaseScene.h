#pragma once
#include "DxLib.h"

// 前方宣言
class SceneManager;

/// <summary>
/// 基底シーンクラス
/// </summary>
class BaseScene
{
private: // メンバ変数
	// シーンマネージャー(借りてくる)
	SceneManager* sceneManager_ = nullptr;

public: // メンバ関数
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~BaseScene() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	virtual void Update(char keys[256], char oldkeys[256]) = 0;

	/// <summary>
	///  描画
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// 終了処理
	/// </summary>
	virtual void Finalize() = 0;

	/// <summary>
	/// シーンマネージャーのセッター
	/// </summary>
	/// <param name="sceneManager"></param>
	virtual void SetSceneManager(SceneManager* sceneManager) { sceneManager_ = sceneManager; }
};