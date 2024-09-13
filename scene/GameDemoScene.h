#pragma once
#include "BaseScene.h"

/// <summary>
/// ゲームデモシーン
/// </summary>
class GameDemoScene : public BaseScene
{
private: // メンバ変数
	int page;
	// 画像データ
	int infoGraph1_;
	int infoGraph2_;
	//BGMデータ
	int titleBgmHandle_;

public: // メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update(char keys[256], char oldkeys[256]) override;

	/// <summary>
	///  描画
	/// </summary>
	void Draw() override;
};