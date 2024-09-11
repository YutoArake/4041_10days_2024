#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize(ObjectStatus status)
{
	// �X�e�[�^�X���
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	// �����ꏊ
	// ��
	if (status_.Y < 0) {
		// ��
		if (status_.X < 32) pos = Posision::LeftTop;
		// �E
		else if (status_.X > 1248) pos = Posision::RightTop;
	}
	// ��
	else if (status_.Y >= 1000) {
		pos = Posision::Under;
		// ��
		if (status_.X < 32) pos = Posision::LeftUnder;
		// �E
		else if (status_.X > 1248) pos = Posision::RightUnder;
	}
	// �^�C�}�[
	timer = 10;

	// �摜�f�[�^
	meteorGraph = LoadGraph("Resources/textures/meteor.png");
	// �����f�[�^
	seHandle = LoadSoundMem("Resources/sounds/se_meteor.mp3");
}

void Meteor::Finalize()
{
}

void Meteor::Update()
{
	switch (pos)
	{
	case Meteor::Posision::LeftTop:
		status_.Y += 3.0f;
		status_.X += 3.0f;
		break;
	case Meteor::Posision::RightTop:
		status_.Y += 3.0f;
		status_.X -= 3.0f;
		break;
	case Meteor::Posision::Under:
		status_.Y -= 1.0f;
		break;
	case Meteor::Posision::LeftUnder:
		status_.Y -= 1.0f;
		status_.X += 1.0f;
		break;
	case Meteor::Posision::RightUnder:
		status_.Y -= 1.0f;
		status_.X -= 1.0f;
		break;
	}

	// �^�C�}�[
	timer--;

	// �S�G�t�F�N�g�̍X�V
	for (auto& effect : effects) { effect->Update(); }

	if (timer <= 0) {
		ObjectStatus status;
		status.X = status_.X;
		status.Y = status_.Y;
		status.R = status_.R;
		// �錾�A����
		std::unique_ptr<FireEffect> effect;
		effect = std::make_unique<FireEffect>();
		effect->Initialize(status);
		// �R���e�i�Ƀv�b�V��
		effects.push_back(std::move(effect));

		timer = 10;
	}
}

void Meteor::Draw(float scroll)
{
	// �S�G�t�F�N�g�̍X�V
	for (auto& effect : effects) { effect->Draw(scroll); }
	DrawGraph(status_.X - 32, status_.Y - 32 - scroll, meteorGraph, true);
}

void Meteor::Collision()
{
	//���������������
	status_.X = -5000;
	// ���ʉ�
	PlaySoundMem(seHandle, DX_PLAYTYPE_BACK);
}
