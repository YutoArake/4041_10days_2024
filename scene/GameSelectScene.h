#pragma once
#include "BaseScene.h"
#include "Vector2.h"
#include <array>

/// <summary>
/// ゲーム選択画面
/// </summary>
class GameSelectScene : public BaseScene
{
public: // 静的メンバ変数
	// 全ステージ数
	static const int STAGE_MAX_NUM = 3;
	// ステージ番号
	static int stageNum_;

private: // メンバ変数
	// クリアマップ数
	std::array<bool, STAGE_MAX_NUM> isStageClear_;

	// 画像データ
	int bgGraph;
	int rocketGraph;

	// 音データ
	int musicHandle;
	int seHandle;

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