#pragma once
#include "BaseScene.h"
#include "Vector2.h"
#include <array>

/// <summary>
/// �Q�[���I�����
/// </summary>
class GameSelectScene : public BaseScene
{
public: // �ÓI�����o�ϐ�
	// �S�X�e�[�W��
	static const int STAGE_MAX_NUM = 3;
	// �X�e�[�W�ԍ�
	static int stageNum_;

private: // �����o�ϐ�
	// �N���A�}�b�v��
	std::array<bool, STAGE_MAX_NUM> isStageClear_;

	// �摜�f�[�^
	int bgGraph;
	int rocketGraph;

	// ���f�[�^
	int musicHandle;
	int seHandle;

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