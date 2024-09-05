#include "SceneManager.h"
#include <cassert>

bool SceneManager::isGameEnd_ = false;

SceneManager* SceneManager::GetInstance()
{
	// 関数内static変数でインスタンス生成
	static SceneManager instance;
	// インスタンスを返す
	return &instance;
}

void SceneManager::Update(char keys[256], char oldkeys[256])
{
#pragma region シーン切り替え機構
	// 次シーンの予約があるなら
	if (nextScene_) {
		// 旧シーンの終了
		if (scene_) {
			scene_->Finalize();
			delete scene_;
		}

		// シーン切り替え
		scene_ = nextScene_;
		nextScene_ = nullptr;

		// シーンマネージャーをセット
		scene_->SetSceneManager(this);

		// 次シーンを初期化する
		scene_->Initialize();
	}
#pragma endregion

	// 実行中シーンを更新する
	scene_->Update(keys, oldkeys);
}

void SceneManager::Draw()
{
	scene_->Draw();
}

void SceneManager::Finalize()
{
	// 最後のシーンの終了と解放
	scene_->Finalize();
	delete scene_;
}

void SceneManager::ChangeScene(const std::string& sceneName)
{
	assert(sceneFactory_);
	assert(nextScene_ == nullptr);

	// 次シーンを生成
	nextScene_ = sceneFactory_->CreateScene(sceneName);
}

void SceneManager::EndGame()
{
	isGameEnd_ = true;
}
