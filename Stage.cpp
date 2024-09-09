#include "Stage.h"
#include "Meteor.h"
#include <cassert>
#include <fstream>

void Stage::Initialize(int stageNum)
{
	// ステージ番号格納
	this->stageNum = stageNum;
	// ステージを読み込む
	LoadStage();
}

void Stage::Update()
{
	// 全オブジェクトの更新
	for (auto& object : objects_) { object->Update(); }
}

void Stage::Draw()
{
	// 全オブジェクトの描画
	for (auto& object : objects_) { object->Draw(); }
}

void Stage::LoadStage()
{
	// バッファをクリア
	stageCommands_.str("");
	// 状態をクリア
	stageCommands_.clear(std::stringstream::goodbit);

	// ギミックコンテナの中身を空にする
	objects_.clear();

	// ステージ読み込み
	LoadStageFile();
	LoadStageCommands();
}

void Stage::LoadStageFile()
{
	// ファイル
	std::ifstream file;
	// パスを取得
	std::string stage[3] = { "1", "2", "3" };
	const std::string stagefile = "stages/";
	const std::string filename = "stage" + stage[stageNum - 1] + ".txt";
	const std::string directoryPath = "Resources/" + stagefile + filename;
	// ファイルを開く
	file.open(directoryPath);
	assert(file.is_open());
	// ファイルの内容を文字列ストリームにコピー
	stageCommands_ << file.rdbuf();
	// ファイルを閉じる
	file.close();
}

void Stage::LoadStageCommands()
{
	// 1行分の文字列を入れる変数
	std::string line;

	// コマンド実行ループ
	while (getline(stageCommands_, line)) {
		// 1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);
		// 文字列
		std::string word;
		// 空白区切りで行の先頭文字列を取得
		getline(line_stream, word, ' ');

		// "//"から始まる行はコメント
		if (word.find("//") == 0) {
			// コメント行を読み飛ばす
			continue;
		}

		// どのギミックを読み込んだかの判別
		ObjectNum objectNum = ObjectNum::None;
		if (word.find("meteor") == 0) { objectNum = ObjectNum::Meteor; }
		else if (word.find("start") == 0) {}
		else { continue; } // 何も読み込まれてなければ次へ

		// コマンド読み込み
		// 引数用変数
		ObjectParam objectParam;
		LoadStreamCommands(line_stream, word, objectParam);

		// ギミック生成
		PopGimmick(objectNum, objectParam);
	}
}

void Stage::LoadStreamCommands(std::istringstream& stream, std::string& word, ObjectParam& objectParam)
{
	// (区切りで先頭文字列を取得
	while (getline(stream, word, '('))
	{
		// 座標取得
		if (word.find("pos") == 0) {
			stream >> objectParam.x;
			stream >> objectParam.y;
		}
		// 空白まで飛ばす
		getline(stream, word, ' ');
	}
}

void Stage::PopGimmick(ObjectNum objectNum, const ObjectParam& objectParam)
{
	// 宣言、生成
	std::unique_ptr<Object> object;
	switch (objectNum)
	{
	case ObjectNum::Meteor:	object = std::make_unique<Meteor>();	break;
	}

	//初期設定
	object->Initialize(objectParam);
	// コンテナにプッシュ
	objects_.push_back(std::move(object));
}
