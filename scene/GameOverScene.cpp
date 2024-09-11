#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// ���j���[
	menu_ = RETRY_STAGE;

	// �摜�f�[�^
	bgGraph = LoadGraph("Resources/textures/select.png");
	// �����f�[�^
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");
}

void GameOverScene::Finalize()
{
}

void GameOverScene::Update(char keys[256], char oldkeys[256])
{
	//BGM�����Ă��Ȃ�������
	if (CheckSoundMem(overBgmHandle_) == 0)
	{
		//�Đ�
		PlaySoundMem(overBgmHandle_, DX_PLAYTYPE_BACK);
	}

	// ���j���[�؂�ւ�
	if (keys[KEY_INPUT_RIGHT] && !oldkeys[KEY_INPUT_RIGHT])
	{
		// �C���N�������g
		menu_++;
		// �l�����j���[���𒴂��Ȃ��悤�ɂ���
		menu_ = std::min<int>(menu_, MENU_MAX_NUM);
	}
	if (keys[KEY_INPUT_LEFT] && !oldkeys[KEY_INPUT_LEFT])
	{
		// �f�N�������g
		menu_--;
		// �l��0�������Ȃ��悤�ɂ���
		menu_ = std::max<int>(menu_, 0);
	}

	// �V�[���؂�ւ�
	if (keys[KEY_INPUT_RETURN] && !oldkeys[KEY_INPUT_RETURN])
	{
		if (menu_ == RETRY_STAGE) {
			// ���ʉ�
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// �Q�[���v���C�V�[����
			SceneManager::GetInstance()->ChangeScene("PLAY");
			//BGM��~
			StopSoundMem(overBgmHandle_);
			return;
		}
		else if (menu_ == RETURN_TO_STAGESELECT) {
			// ���ʉ�
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// �Z���N�g�V�[����
			SceneManager::GetInstance()->ChangeScene("SELECT");
			//BGM��~
			StopSoundMem(overBgmHandle_);
			return;
		}
		else if (menu_ == RETURN_TO_TITLE) {
			// ���ʉ�
			//PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
			// �^�C�g����
			SceneManager::GetInstance()->ChangeScene("TITLE");
			//BGM��~
			StopSoundMem(overBgmHandle_);
			return;
		}
	}
}

void GameOverScene::Draw()
{
	DrawGraph(0, 0, bgGraph, true);
	// �f�o�b�N�e�L�X�g
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[���I�[�o�[�V�[��");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", menu_);
}