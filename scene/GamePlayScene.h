#pragma once
#include "BaseScene.h"
#include "player.h"
#include "item.h"

/// <summary>
/// �Q�[���v���C�V�[��
/// </summary>
class GamePlayScene : public BaseScene
{
private: // �����o�ϐ�
	bool isClear = false;

	
	Player* player = new Player();//player
	Item* item = new Item();

	int scroll; //�X�N���[�����W
	int image_123;//�w�i�摜

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