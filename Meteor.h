#pragma once
#include "Object.h"

/// <summary>
/// ���e�I(�q�N���X)
/// </summary>
class Meteor : public Object
{
private: // �����o�ϐ�
	

	// �摜�f�[�^
	int meteorGraph;
	int flameGraph;

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize() override;

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
	void Draw() override;
};