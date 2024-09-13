#pragma once
#include "BaseScene.h"

/// <summary>
/// ゲームオーバーシーン
/// </summary>
class GameOverScene : public BaseScene
{
	//列挙型
	enum Menu {
		RETRY_STAGE,
		RETURN_TO_STAGESELECT,
		RETURN_TO_TITLE,
	};
private: // メンバ変数
	// メニュー
	int menu_;
	const int MENU_MAX_NUM = 2;
	int timer_;

	// 画像データ
	int bgGraph;
	int pGraph;
	int retryStageGraph;
	int toSelectGraph;
	int toTitleGraph;

	// 音データ
	int overBgmHandle_;

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