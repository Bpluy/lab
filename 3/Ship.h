#pragma once

using namespace std;

class Ship
{
private:
	string Name;	//��������
	int Displacement;	//�������������
	string Type;	//���

public:
	Ship(); //����������� ��� ����������
	Ship(string name, string type, int deplacement);	//����������� � �����������
	Ship(const Ship& ship);	//����������� �����������

	virtual void Show();

	string GetName();
	string GetType();
	int GetDisplacement();
	void SetName(string Name);
	void SetType(string Type);
	void SetDisplacement(int Displacement);


	~Ship();
};

class Steamboat : public Ship
{
private:
	int Power;

public:
	Steamboat();
	Steamboat(string Name, string Type, int Displacement, int Power);
	Steamboat(const Steamboat& original);

	void Show();
	int GetPower();
	void SetPower(int Power);

	~Steamboat();
};

class Sailboat : public Ship
{
	int MastsNumber;			//���-�� ����

public:
	Sailboat();
	Sailboat(string Name, string Type, int Displacement, int MastsNumber);
	Sailboat(const Sailboat& original);

	void Show();

	int GetMNumber();
	void SetMNumber(int MastsNumber);

	~Sailboat();
};

class Corvette : public Ship
{
	int Complement;			// ������ (���-��)

public:
	Corvette();
	Corvette(string Name, string Type, int Displacement, int Complement);
	Corvette(const Corvette& original);

	void Show();

	int GetComplement();
	void SetComplement(int Complement);

	~Corvette();
};

class Contain : public Ship
{
private:
	int count = 0;
	Ship** arr = new Ship*[1];
	Ship** buf = new Ship*[2];

public:
	void Add(int,Ship*);
	void Show(int);
	void Del(int num);

	~Contain();
};