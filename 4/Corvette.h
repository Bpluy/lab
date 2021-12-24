#pragma once
#include "Ship.h"
class Corvette : public Ship
{
	int Complement;			// Ёкипаж (кол-во)

public:
	Corvette();
	Corvette(string Type, bool random = false);
	Corvette(string Name, string Type, int Displacement, int Complement);
	Corvette(const Corvette& original);

	void Show();

	int GetComplement();
	void SetComplement(int Complement);

	struct structCorvette : structShip
	{
		int Complement;
	};

	~Corvette();
};

