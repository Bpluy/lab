#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Ship.h"


Ship::Ship(string type,bool random)
{
	if (random == false)
	{
		cout << "\nEnter a Name of ship:" << endl;
		cin >> this->Name;
		cout << "\nEnter a displacement for " << this->Name << endl;
		cin >> this->Displacement;
		this->Type = type;
	}
	else
	{
		srand(time(0));
		static string Names[7] = { "Arizona","Flying Dutchman","Black Pearl","Silent Mary","Queen Anne's Revenge","HMS Dauntless","Dying Gull" };
		this->Name = Names[rand() % 7];
		this->Displacement = rand() % 2500;
		this->Type = type;
	}
}

Ship::Ship()
{
	this->Name = "";
	this->Displacement = 0;
	this->Type = "";
}

Ship::Ship(string name, string type, int displacement)
{
	this->Name = name;
	this->Displacement = displacement;
	this->Type = type;
}

Ship::Ship(const Ship& ship)
{
	this->Name = ship.Name + " copy";
	this->Type = ship.Type;
	this->Displacement = ship.Displacement;
}

void Ship::Show()
{
	cout << "Name: " << Name << " Type: " << Type  << " Displacement: " << Displacement << endl;
}

string Ship::GetName() { return Name; }

int Ship::GetDisplacement() { return Displacement; }

string Ship::GetType() { return Type; }

void Ship::SetName(string Name) { this->Name = Name; }

void Ship::SetDisplacement(int Displacement) { this->Displacement = Displacement; }

void Ship::SetType(string Type) { this->Type = Type; }

Ship::~Ship() {}
