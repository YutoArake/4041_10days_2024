#pragma once

/// <summary>
/// Vector2
/// </summary>
class Vector2
{

public:
	//メンバ変数
	float x;
	float y;

	//コンストラクタ
	Vector2();					//零ベクトルとして生成
	Vector2(float x, float y);	//x成分,y成分を指定しての生成

	//メンバ関数
	float length() const;
	Vector2& nomalize();
	float dot(const Vector2& v) const;
	float cross(const Vector2& v) const;

	//単項演算子オーバーロード
	Vector2 operator+() const;
	Vector2 operator-() const;

	//代入演算子オーバーロード
	Vector2 operator+=(const Vector2& v);
	Vector2 operator-=(const Vector2& v);
	Vector2 operator*=(float s);
	Vector2 operator/=(float s);

	//比較演算子
	bool operator == (const Vector2& v);
	bool operator != (const Vector2& v);

};

//2項演算子オーバーロード
//いろんな引数(引数の型と順序)のパターンに対応するために、以下のように準備している
const Vector2& operator+(const Vector2& v1, const Vector2& v2);
const Vector2& operator-(const Vector2& v1, const Vector2& v2);
const Vector2& operator*(const Vector2& v, float s);
const Vector2& operator*(float s, const Vector2& v);
const Vector2& operator/(const Vector2& v, float s);

