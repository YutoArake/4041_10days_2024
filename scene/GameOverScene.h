#pragma once
#include "BaseScene.h"

/// <summary>
/// �Q�[���I�[�o�[�V�[��
/// </summary>
class GameOverScene : public BaseScene
{
	//�񋓌^
	enum Menu {
		RETRY_STAGE,
		RETURN_TO_STAGESELECT,
		RETURN_TO_TITLE,
	};
private: // �����o�ϐ�
	// ���j���[
	int menu_;
	const int MENU_MAX_NUM = 2;
	int timer_;

	// �摜�f�[�^
	int bgGraph;
	int pGraph;
	int retryStageGraph;
	int toSelectGraph;
	int toTitleGraph;

	// ���f�[�^
	int overBgmHandle_;

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