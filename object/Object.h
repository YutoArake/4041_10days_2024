#pragma once
#include <vector>

/// <summary>
/// �I�u�W�F�N�g�X�e�[�^�X�̍\����
/// </summary>
struct ObjectStatus
{
	float X;		//���WX
	float Y;		//���WY
	float R;		//���a
	char Tag;		//�^�O
};

/// <summary>
/// �I�u�W�F�N�g�N���X(�e�N���X)
/// </summary>
class Object
{
protected: // �����o�ϐ�
	// �X�e�[�^�X
	ObjectStatus status_;

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize(ObjectStatus status) = 0;

	/// <summary>
	/// ���t���[���X�V
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	///  �`��
	/// </summary>
	virtual void Draw(float scroll) = 0;

	/// <summary>
	/// �I������
	/// </summary>
	virtual void Finalize() = 0;

	// �����蔻��
	virtual void Collision() = 0;

	// �Q�b�^�[
	ObjectStatus GetStatus() { return status_; }
};