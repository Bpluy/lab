#include <string>
#include <iostream>
#include <stdlib.h>

#include "Steamboat.h"

Steamboat::Steamboat() : Ship(), Power(0){}

Steamboat::Steamboat(string Type, bool random)  : Ship(Type, random)
{
	if (random == false)
	{
		cout << "\nEnter a power for " << GetName() << endl;
		cin >> this->Power;
	}
	else
	{
		srand(time(0));
		this->Power = rand() % 25000;
	}
}

Steamboat::Steamboat(string Name, string Type, int Displacement, int Power) : Ship(Name, Type, Displacement)
{
	this->Power = Power;
}

Steamboat::Steamboat(const Steamboat& original) : Ship(original)
{
	this->Power = original.Power;
}

void Steamboat::Show()
{
	Ship::Show();
	cout << " | Power: " << GetPower() << endl;
}

int Steamboat::GetPower() { return this->Power; }

void Steamboat::SetPower(int Power) { this->Power = Power; }

Steamboat::~Steamboat() {}
