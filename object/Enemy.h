#pragma once
#include "DxLib.h"
#include <math.h>

#include "Object.h"

/// <summary>
/// アイテム
/// </summary>
class Enemy : public Object
{
public: // メンバ関数
	// 初期化
	void Initialize(ObjectStatus status) override;
	// 終了処理
	void Finalize() override;
	// 更新
	void Update() override;
	// 描画
	void Draw(float scroll) override;
	// 当たり判定
	void Collision() override;
	//動き
	void Move();


private:
	int speed_;

	int saveSpeed_;
	bool isMove_;
	int stopTime_;
	int stopTimer_;

	int imageEnemy1_; //Enemy用の画像
	int imageEnemy2_; 
	int imageEnemy3_; 

	int randTime_;
	int randTimer_;
	int randSpeed_;

};