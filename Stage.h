#pragma once
#include "Object.h"
#include "player.h"
#include <sstream>

/// <summary>
/// ステージ
/// </summary>
class Stage
{
	/// <summary>
	/// オブジェクトの番号列挙
	/// </summary>
	enum class ObjectNum
	{
		None,
		Meteor,
		Item,
		Enemy
	};

private: // メンバ変数
	// ステージ番号
	int stageNum;
	// オブジェクト格納用
	std::vector<std::unique_ptr<Object>> objects_;

	// ファイルコマンド
	std::stringstream stageCommands_;

public: // メンバ関数
	// 初期化
	void Initialize(int stageNum);

	// 更新
	void Update();

	// 描画
	void Draw(float scroll);

	// 当たり判定
	void ObjectCollision(Player* p);

private: // メンバ関数
	// ステージ読み込み
	void LoadStage();
	// ステージファイル読み込み
	void LoadStageFile();
	// コマンド読み込み
	void LoadStageCommands();
	// ストリームコマンド読み込み
	void LoadStreamCommands(std::istringstream& stream, std::string& word, ObjectStatus& status);
	// ギミック生成
	void PopGimmick(ObjectNum objectNum, const ObjectStatus& status);
};