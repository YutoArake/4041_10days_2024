#pragma once
#include "DxLib.h"

#include "DxLib.h"
#include "Object.h"

/// <summary>
/// �A�C�e��
/// </summary>
class Enemy : public Object
{
public: // �����o�֐�
	// ������
	void Initialize(ObjectStatus status) override;
	// �I������
	void Finalize() override;
	// �X�V
	void Update() override;
	// �`��
	void Draw(float scroll) override;
	// �����蔻��
	void Collision() override;
	//����
	void Move();

private:
	int speed;
	int saveSpeed;
	bool isMove;
	int stopTimer;
};