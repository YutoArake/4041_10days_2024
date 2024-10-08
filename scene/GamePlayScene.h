#pragma once
#include "BaseScene.h"
#include "Enemy.h"
#include "player.h"
#include "Stage.h"

/// <summary>
/// ゲームプレイシーン
/// </summary>
class GamePlayScene : public BaseScene
{
private: // メンバ変数
	Stage stage;
	bool isClear = false;

	Enemy enemy_;
	//BGMデータ
	int playBgmHandle_;

public: // �����o�֐�
	
	Player* player = new Player();//player

	float scroll; //スクロール座標
	int image_back1;//背景画像
	int image_back2;//背景画像
	int image_back3;//背景画像

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