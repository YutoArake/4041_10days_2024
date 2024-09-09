#include "Stage.h"
#include "Meteor.h"
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

void Stage::Draw()
{
	// �S�I�u�W�F�N�g�̕`��
	for (auto& object : objects_) { object->Draw(); }
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
		else if (word.find("start") == 0) {}
		else { continue; } // �����ǂݍ��܂�ĂȂ���Ύ���

		// �R�}���h�ǂݍ���
		// �����p�ϐ�
		ObjectParam objectParam;
		LoadStreamCommands(line_stream, word, objectParam);

		// �M�~�b�N����
		PopGimmick(objectNum, objectParam);
	}
}

void Stage::LoadStreamCommands(std::istringstream& stream, std::string& word, ObjectParam& objectParam)
{
	// (��؂�Ő擪��������擾
	while (getline(stream, word, '('))
	{
		// ���W�擾
		if (word.find("pos") == 0) {
			stream >> objectParam.x;
			stream >> objectParam.y;
		}
		// �󔒂܂Ŕ�΂�
		getline(stream, word, ' ');
	}
}

void Stage::PopGimmick(ObjectNum objectNum, const ObjectParam& objectParam)
{
	// �錾�A����
	std::unique_ptr<Object> object;
	switch (objectNum)
	{
	case ObjectNum::Meteor:	object = std::make_unique<Meteor>();	break;
	}

	//�����ݒ�
	object->Initialize(objectParam);
	// �R���e�i�Ƀv�b�V��
	objects_.push_back(std::move(object));
}
