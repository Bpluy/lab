#pragma once

using namespace std;

class Ship
{
private:
	string Name;	//Название
	int Displacement;	//Водоизмещение
	string Type;	//Тип

public:
	Ship();
	Ship(string type,bool random = false); //Конструктор без параметров
	Ship(string name, string type, int deplacement);	//Конструктор с параметрами
	Ship(const Ship& ship);	//Конструктор копирования

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
