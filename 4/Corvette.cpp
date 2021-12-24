#include <string>
#include <iostream>
#include <stdlib.h>

#include "Corvette.h"

Corvette::Corvette() : Ship(),Complement(0){}

Corvette::Corvette(string Type, bool random) : Ship(Type,random)
{
	if (random == false)
	{
		cout << "\nEnter a complement for " << GetName() << endl;
		cin >> this->Complement;
	}
	else
	{
		srand(time(0));
		this->Complement = rand() % 200 + 10;
	}	
}

Corvette::Corvette(string Name, string Type, int Displacement, int Complement) : Ship(Name, Type, Displacement)
{
	this->Complement = Complement;
}

Corvette::Corvette(const Corvette& original) : Ship(original)
{
	this->Complement = original.Complement;
}

void Corvette::Show()
{
	Ship::Show();
	cout << " | Complement: " << GetComplement() << endl;
}

int Corvette::GetComplement() { return this->Complement; }

void Corvette::SetComplement(int Complement) { this->Complement = Complement; }

Corvette::~Corvette() {}