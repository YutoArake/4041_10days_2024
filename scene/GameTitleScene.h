#pragma once
#include "BaseScene.h"

/// <summary>
///	 ゲームタイトルシーン
/// </summary>
class GameTitleScene : public BaseScene
{
private: // メンバ変数
	// 画像データ
	int titleGraph_;
	int pressEnterGraph_;
	//BGMデータ
	int titleBgmHandle_;
	int seHandle;

	//アルファ値
	int alpha_;
	int add_;

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