#pragma once
#include "Ship.h"
class Steamboat : public Ship
{
private:
	int Power;

public:
	Steamboat();
	Steamboat(string Type, bool random = false);
	Steamboat(string Name, string Type, int Displacement, int Power);
	Steamboat(const Steamboat& original);

	void Show();
	int GetPower();
	void SetPower(int Power);

	struct structSteamboat : structShip
	{
		int Power;
	};

	~Steamboat();
};
