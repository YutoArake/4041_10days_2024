#pragma once
#include "Object.h"
#include "player.h"
#include <sstream>

/// <summary>
/// �X�e�[�W
/// </summary>
class Stage
{
	/// <summary>
	/// �I�u�W�F�N�g�̔ԍ���
	/// </summary>
	enum class ObjectNum
	{
		None,
		Meteor,
		Item,
		Enemy
	};

private: // �����o�ϐ�
	// �X�e�[�W�ԍ�
	int stageNum;
	// �I�u�W�F�N�g�i�[�p
	std::vector<std::unique_ptr<Object>> objects_;

	// �t�@�C���R�}���h
	std::stringstream stageCommands_;

public: // �����o�֐�
	// ������
	void Initialize(int stageNum);

	// �X�V
	void Update();

	// �`��
	void Draw(float scroll);

	// �����蔻��
	void ObjectCollision(Player* p);

private: // �����o�֐�
	// �X�e�[�W�ǂݍ���
	void LoadStage();
	// �X�e�[�W�t�@�C���ǂݍ���
	void LoadStageFile();
	// �R�}���h�ǂݍ���
	void LoadStageCommands();
	// �X�g���[���R�}���h�ǂݍ���
	void LoadStreamCommands(std::istringstream& stream, std::string& word, ObjectStatus& status);
	// �M�~�b�N����
	void PopGimmick(ObjectNum objectNum, const ObjectStatus& status);
};