#pragma once
#include "Object.h"

/// <summary>
/// �t�@�C�A�G�t�F�N�g
/// </summary>
class FireEffect : public Object
{
private: // �����o�ϐ�
	// ��]�x�A�g�k
	double rotate;
	double scale;
	// �摜�f�[�^
	int fireEffect;

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