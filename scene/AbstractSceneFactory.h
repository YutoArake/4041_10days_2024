#pragma once
#include "BaseScene.h"
#include <string>

/// <summary>
/// シーン工場(概念)
/// </summary>
class AbstractSceneFactory
{
public: // メンバ関数
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~AbstractSceneFactory() = default;

	/// <summary>
	/// シーン生成
	/// </summary>
	/// <param name="sceneName">シーン名</param>
	/// <returns></returns>
	virtual BaseScene* CreateScene(const std::string& sceneName) = 0;
};