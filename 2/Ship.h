#pragma once

using namespace std;

class Ship
{
private:
	string Name;	//��������
	int Displacement;	//�������������
	string Type;	//���

	static int Count;
public:
	Ship(); //����������� ��� ����������
	Ship(string name, int deplacement, string type);	//����������� � �����������
	Ship(const Ship& ship);	//����������� �����������

	void Show();
	const string GetName();
	const string GetType();
	int GetDisplacement();
	static int GetCount();
	void SetName(string Name);
	void SetType(string Type);
	void SetDisplacement(int Displacement);


	~Ship();
};

