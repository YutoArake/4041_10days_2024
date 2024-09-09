#include "Stage.h"
#include "Meteor.h"
#include "item.h"
#include "Enemy.h"
#include <cassert>
#include <fstream>

void Stage::Initialize(int stageNum)
{
	// �X�e�[�W�ԍ��i�[
	this->stageNum = stageNum;
	// �X�e�[�W��ǂݍ���
	LoadStage();
}

void Stage::Update()
{
	// �S�I�u�W�F�N�g�̍X�V
	for (auto& object : objects_) { object->Update(); }
}

void Stage::Draw(float scroll)
{
	// �S�I�u�W�F�N�g�̕`��
	for (auto& object : objects_) { object->Draw(scroll); }
}

void Stage::LoadStage()
{
	// �o�b�t�@���N���A
	stageCommands_.str("");
	// ��Ԃ��N���A
	stageCommands_.clear(std::stringstream::goodbit);

	// �M�~�b�N�R���e�i�̒��g����ɂ���
	objects_.clear();

	// �X�e�[�W�ǂݍ���
	LoadStageFile();
	LoadStageCommands();
}

void Stage::LoadStageFile()
{
	// �t�@�C��
	std::ifstream file;
	// �p�X���擾
	std::string stage[3] = { "1", "2", "3" };
	const std::string stagefile = "stages/";
	const std::string filename = "stage" + stage[stageNum - 1] + ".txt";
	const std::string directoryPath = "Resources/" + stagefile + filename;
	// �t�@�C�����J��
	file.open(directoryPath);
	assert(file.is_open());
	// �t�@�C���̓��e�𕶎���X�g���[���ɃR�s�[
	stageCommands_ << file.rdbuf();
	// �t�@�C�������
	file.close();
}

void Stage::LoadStageCommands()
{
	// 1�s���̕����������ϐ�
	std::string line;

	// �R�}���h���s���[�v
	while (getline(stageCommands_, line)) {
		// 1�s���̕�������X�g���[���ɕϊ����ĉ�͂��₷������
		std::istringstream line_stream(line);
		// ������
		std::string word;
		// �󔒋�؂�ōs�̐擪��������擾
		getline(line_stream, word, ' ');

		// "//"����n�܂�s�̓R�����g
		if (word.find("//") == 0) {
			// �R�����g�s��ǂݔ�΂�
			continue;
		}

		// �ǂ̃M�~�b�N��ǂݍ��񂾂��̔���
		ObjectNum objectNum = ObjectNum::None;
		if (word.find("meteor") == 0) { objectNum = ObjectNum::Meteor; }
		else if (word.find("item") == 0) { objectNum = ObjectNum::Item; }
		else if (word.find("enemy") == 0) { objectNum = ObjectNum::Enemy; }
		else if (word.find("start") == 0) {}
		else { continue; } // �����ǂݍ��܂�ĂȂ���Ύ���

		// �R�}���h�ǂݍ���
		// �����p�ϐ�
		ObjectStatus status;
		LoadStreamCommands(line_stream, word, status);

		// �M�~�b�N����
		PopGimmick(objectNum, status);
	}
}

void Stage::LoadStreamCommands(std::istringstream& stream, std::string& word, ObjectStatus& status)
{
	// (��؂�Ő擪��������擾
	while (getline(stream, word, '('))
	{
		// ���W�擾
		if (word.find("pos") == 0) {
			stream >> status.X;
			stream >> status.Y;
		}
		else if (word.find("rad") == 0) {
			stream >> status.R;
		}
		else if (word.find("tag") == 0) {
			stream >> status.Tag;
		}
		// �󔒂܂Ŕ�΂�
		getline(stream, word, ' ');
	}
}

void Stage::PopGimmick(ObjectNum objectNum, const ObjectStatus& status)
{
	// �錾�A����
	std::unique_ptr<Object> object;
	switch (objectNum)
	{
	case ObjectNum::Meteor:	object = std::make_unique<Meteor>();	break;
	case ObjectNum::Item:		object = std::make_unique<Item>();		break;
	case ObjectNum::Enemy:		object = std::make_unique<Enemy>();		break;
	}

	//�����ݒ�
	object->Initialize(status);
	// �R���e�i�Ƀv�b�V��
	objects_.push_back(std::move(object));
}

void Stage::ObjectCollision(Player* p)
{
	// �S�I�u�W�F�N�g�̓����蔻��
	for (auto& object : objects_) {
		// �v���C���[�ƃI�u�W�F�N�g�̍��W�擾
		int x1 = p->GetStatus().X, y1 = p->GetStatus().Y, r1 = p->GetStatus().R;
		int x2 = object->GetStatus().X, y2 = object->GetStatus().Y, r2 = object->GetStatus().R;

		if (x1 - r1 < x2 + r2 && x2 - r2 < x1 + r1) {
			if (y1 - r1 < y2 + r2 && y2 - r2 < y1 + r1) {
				p->Collision(object->GetStatus().Tag);
				object->Collision();
			}
		}
	}
}