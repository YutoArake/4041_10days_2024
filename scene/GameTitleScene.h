#pragma once
#include "BaseScene.h"

/// <summary>
///	 �Q�[���^�C�g���V�[��
/// </summary>
class GameTitleScene : public BaseScene
{
private: // �����o�ϐ�
	// �摜�f�[�^
	int titleGraph_;
	//BGM�f�[�^
	int titleBgmHandle_;

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
	void Update(char keys[256], char oldkeys[256]) override;

	/// <summary>
	///  �`��
	/// </summary>
	void Draw() override;
};