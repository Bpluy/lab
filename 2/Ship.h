#pragma once

using namespace std;

class Ship
{
private:
	string Name;	//Название
	int Displacement;	//Водоизмещение
	string Type;	//Тип

	static int Count;
public:
	Ship(); //Конструктор без параметров
	Ship(string name, int deplacement, string type);	//Конструктор с параметрами
	Ship(const Ship& ship);	//Конструктор копирования

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

