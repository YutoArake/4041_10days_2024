#pragma once
#include "Object.h"
#include "FireEffect.h"
#include <iostream>

/// <summary>
/// ���e�I(�q�N���X)
/// </summary>
class Meteor : public Object
{
	// ��
	enum class Posision {
		LeftTop,
		RightTop,
		Under,
		LeftUnder,
		RightUnder
	};

private: // �����o�ϐ�
	// �摜�f�[�^
	int meteorGraph;
	// �����f�[�^
	int seHandle;

	// �����ꏊ�ŋ�����ς��邽�߂̕ϐ�
	Posision pos;

	// �G�t�F�N�g�p�^�C�}�[
	int timer;
	// �G�t�F�N�g�R���e�i
	std::vector<std::unique_ptr<FireEffect>> effects;

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(ObjectStatus status) override;

	/// <summary>
	/// �I������
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	void Update() override;

	/// <summary>
	///  �`��
	/// </summary>
	void Draw(float scroll) override;

	// �����蔻��
	void Collision() override;
};