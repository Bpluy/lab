#include <string>
#include <iostream>
#include <stdlib.h>

#include "Sailboat.h"

Sailboat::Sailboat() : Ship(), MastsNumber(0){}

Sailboat::Sailboat(string Type, bool random) : Ship(Type, random)
{
	if (random == false)
	{
		cout << "\nEnter a number of masts for " << GetName() << endl;
		cin >> this->MastsNumber;
	}
	else
	{
		srand(time(0));
		this->MastsNumber = rand() % 3 + 1;
	}
}

Sailboat::Sailboat(string Name, string Type, int Displacement, int MastsNumber) : Ship(Name, Type, Displacement)
{
	this->MastsNumber = MastsNumber;
}

Sailboat::Sailboat(const Sailboat& original) : Ship(original)
{
	this->MastsNumber = original.MastsNumber;
}

void Sailboat::Show()
{
	Ship::Show();
	cout << " | Masts Number: " << GetMNumber() << endl;
}

int Sailboat::GetMNumber() { return this->MastsNumber; }

void Sailboat::SetMNumber(int MastsNumber) { this->MastsNumber = MastsNumber; }

Sailboat::~Sailboat() {}
