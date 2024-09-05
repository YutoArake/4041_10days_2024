#pragma once
#include "AbstractSceneFactory.h"
#include "BaseScene.h"

/// <summary>
/// シーン管理
/// </summary>
class SceneManager final
{
	//静的メンバ変数
private:
	//ゲーム終了フラグ
	static bool isGameEnd_;

private: // メンバ変数
	// シーンファクトリー(借りてくる)
	AbstractSceneFactory* sceneFactory_ = nullptr;
	// 現在シーン(実行中のシーン)
	BaseScene* scene_ = nullptr;
	// 次のシーン
	BaseScene* nextScene_ = nullptr;


public: // 静的メンバ関数
	/// <summary>
	/// シングルトンインスタンス
	/// </summary>
	/// <returns>インスタンス</returns>
	static SceneManager* GetInstance();

public: // メンバ関数
	/// <summary>
	/// 毎フレーム更新
	/// </summary>
	void Update(char keys[256], char oldkeys[256]);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 終了処理
	/// </summary>
	void Finalize();

	/// <summary>
	/// 次シーン予約
	/// </summary>
	/// <param name="sceneName">シーン名</param>
	void ChangeScene(const std::string& sceneName);

	/// <summary>
	/// ゲームを終了する
	/// </summary>
	void EndGame();

public: // アクセッサ
	/// <summary>
	/// シーンファクトリーのセッター
	/// </summary>
	/// <param name="sceneFactory"></param>
	void SetSceneFactory(AbstractSceneFactory* sceneFactory) { sceneFactory_ = sceneFactory; }

	/// <summary>
	/// ゲーム終了フラグを取得する
	/// </summary>
	/// <returns></returns>
	bool GetIsGameEnd() {
		return isGameEnd_;
	}

private: // メンバ関数(シングルトン化)
	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManager() = default;

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SceneManager() = default;

	/// <summary>
	/// コピーコンストラクタを無効化
	/// </summary>
	/// <param name="">入力</param>
	SceneManager(const SceneManager&) = delete;

	/// <summary>
	/// 代入演算子を無効化
	/// </summary>
	/// <param name="">入力</param>
	/// <returns></returns>
	const SceneManager& operator=(const SceneManager&) = delete;
};