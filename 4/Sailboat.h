#pragma once
#include "Ship.h"
class Sailboat : public Ship
{
	int MastsNumber;			//кол-во мачт

public:
	Sailboat();
	Sailboat(string Type, bool random = false);
	Sailboat(string Name, string Type, int Displacement, int MastsNumber);
	Sailboat(const Sailboat& original);

	void Show();

	int GetMNumber();
	void SetMNumber(int MastsNumber);

	struct structSailboat : structShip
	{
		int MastsNumber;
	};

	~Sailboat();
};
