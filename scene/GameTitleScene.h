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
	int pressEnterGraph_;
	//BGM�f�[�^
	int titleBgmHandle_;
	int seHandle;

	//�A���t�@�l
	int alpha_;
	int add_;

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