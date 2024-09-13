#pragma once
#include "BaseScene.h"

/// <summary>
/// �Q�[���f���V�[��
/// </summary>
class GameDemoScene : public BaseScene
{
private: // �����o�ϐ�
	int page;
	// �摜�f�[�^
	int infoGraph1_;
	int infoGraph2_;
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