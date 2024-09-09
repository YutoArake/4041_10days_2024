#include "Meteor.h"
#include "DxLib.h"

void Meteor::Initialize(ObjectStatus status)
{
	// �X�e�[�^�X���
	status_.X = status.X;
	status_.Y = status.Y;
	status_.R = status.R;
	status_.Tag = status.Tag;

	// �^�C�}�[
	timer = 10;

	// �摜�f�[�^
	meteorGraph = LoadGraph("Resources/textures/meteor.png");
}

void Meteor::Finalize()
{
}

void Meteor::Update()
{
	status_.Y -= 1.0f;
	timer--;

	// �S�G�t�F�N�g�̍X�V
	for (auto& effect : effects) { effect->Update(); }

	if (timer <= 0) {
		ObjectStatus status;
		status.X = status_.X;
		status.Y = status_.Y;
		status.R = 32;
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
	status_.X = -50;
}
