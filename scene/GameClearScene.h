#pragma once
#include "BaseScene.h"

/// <summary>
/// �Q�[���N���A�V�[��
/// </summary>
class GameClearScene : public BaseScene
{
	//�񋓌^
	enum Menu {
		NEXT_STAGE,
		RETURN_TO_STAGESELECT,
		RETURN_TO_TITLE,
	};

private: // �����o�ϐ�
	// ���j���[
	int menu_;
	const int MENU_MAX_NUM = 2;
	bool isFainalStage;

	// �摜�f�[�^
	int bgGraph;
	int nextStageGraph;
	int toSelectGraph;
	int toTitleGraph;

	// ���f�[�^
	int clearBgmHandle_;
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