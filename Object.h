#pragma once
#include "Vector2.h"

/// <summary>
/// �I�u�W�F�N�g�N���X(�e�N���X)
/// </summary>
class Object
{
protected: // �����o�ϐ�
	// ���W
	Vector2 pos;

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	///  �`��
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// �I������
	/// </summary>
	virtual void Finalize() = 0;
};