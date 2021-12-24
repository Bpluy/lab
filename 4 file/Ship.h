#pragma once
#include <vector>

using namespace std;
using std::vector;

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


//class Steamboat : public Ship
//{
//private:
//	int Power;
//
//public:
//	Steamboat();
//	Steamboat(string Name, string Type, int Displacement, int Power);
//	Steamboat(const Steamboat& original);
//
//	void Show();
//	int GetPower();
//	void SetPower(int Power);
//
//	~Steamboat();
//};





