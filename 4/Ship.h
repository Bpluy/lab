#pragma once

using namespace std;

class Ship
{
private:
	string Name;	//��������
	int Displacement;	//�������������
	string Type;	//���

public:
	Ship();
	Ship(string type,bool random = false); //����������� ��� ����������
	Ship(string name, string type, int deplacement);	//����������� � �����������
	Ship(const Ship& ship);	//����������� �����������

	virtual void Show();

	string GetName();
	int GetDisplacement();
	string GetType();
	void SetName(string Name);
	void SetDisplacement(int Displacement);
	void SetType(string Type);

	struct structShip
	{
		string Name;
		int Displacement;
		string Type;
	};

	~Ship();
};
