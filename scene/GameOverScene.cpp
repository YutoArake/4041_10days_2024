#include "GameOverScene.h"
#include "SceneManager.h"

void GameOverScene::Initialize()
{
	// ���j���[
	menu_ = RETRY_STAGE;

	// �摜�f�[�^
	bgGraph = LoadGraph("Resources/textures/select.png");
	pGraph = LoadGraph("Resources/textures/yajirushi.png");
	retryStageGraph = LoadGraph("Resources/textures/retry.png");
	toSelectGraph = LoadGraph("Resources/textures/selectScene.png");
	toTitleGraph = LoadGraph("Resources/textures/titleScene.png");
	// �����f�[�^
	overBgmHandle_ = LoadSoundMem("BGM/gameOver.mp3");
	//seHandle = LoadSoundMem("Resources/sounds/.mp3");

	alpha_ = 255;
	add_ = -5;
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

	// �_��
	alpha_ += add_;

	// �A���t�@�l�� 0 �� 255 �ɂȂ�����ω��̕����𔽓]����
	if (alpha_ == 0 || alpha_ == 255)
	{
		add_ = -add_;
	}


	// ���j���[�؂�ւ�
	if (keys[KEY_INPUT_DOWN] && !oldkeys[KEY_INPUT_DOWN])
	{
		// �C���N�������g
		menu_++;
		// �l�����j���[���𒴂��Ȃ��悤�ɂ���
		menu_ = std::min<int>(menu_, MENU_MAX_NUM);
	}
	if (keys[KEY_INPUT_UP] && !oldkeys[KEY_INPUT_UP])
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
	// �I��
	switch (menu_)
	{
	case RETRY_STAGE:
		DrawGraph(350, 325, pGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 300, retryStageGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 400, toSelectGraph, true);
		DrawGraph(0, 500, toTitleGraph, true);
		break;
	case RETURN_TO_STAGESELECT:
		DrawGraph(350, 425, pGraph, true);
		DrawGraph(0, 300, retryStageGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 400, toSelectGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawGraph(0, 500, toTitleGraph, true);
		break;
	case RETURN_TO_TITLE:
		DrawGraph(350, 525, pGraph, true);
		DrawGraph(0, 300, retryStageGraph, true);
		DrawGraph(0, 400, toSelectGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
		DrawGraph(0, 500, toTitleGraph, true);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		break;
	}
	// �f�o�b�N�e�L�X�g
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�Q�[���I�[�o�[�V�[��");
	DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", menu_);
}