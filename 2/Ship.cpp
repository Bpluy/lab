#include <string>
#include <iostream>

#include "Ship.h"

int Ship::Count = 0;

Ship::Ship()
{
	this->Name = "N/A";
	this->Type = "N/A";
	this->Displacement = 0;
	cout << "Ship: " << Name << " was created without parameters. ID: " << this << endl;
	++Count;
}

Ship::Ship(string name, int displacement, string type)
{
	this->Name = name;
	this->Displacement = displacement;
	this->Type = type;
	cout << "Ship: " << Name << " was created. ID: " << this << endl;
	++Count;
}

Ship::Ship(const Ship& ship)
{
	this->Name = ship.Name + " copy";
	this->Type = ship.Type;
	this->Displacement = ship.Displacement;
	cout << "Ship: " << Name << " was copied from the " << ship.Name << " ID: " << this << endl;
	++Count;
}

void Ship::Show()
{
	cout << "Ship: " << Name << "\nDisplacement: " << Displacement << "\nType: " << Type << endl;
}

const string Ship::GetName()
{
	return Name;
}

const string Ship::GetType()
{
	return Type;
}

int Ship::GetDisplacement()
{
	return Displacement;
}

int Ship::GetCount()
{
	return Count;
}

void Ship::SetName(string Name)
{
	string Name_ = this->Name;
	this->Name = Name;
	cout << "New name: " << Name_ << " is " << Name << endl;
}

void Ship::SetType(string Type)
{
	this->Type = Type;
	cout << "For " << Name << " type was changing to " << Type << endl;
}

void Ship::SetDisplacement(int Displacement)
{
	this->Displacement = Displacement;
	cout << "For " << Name << " displacement was changing to " << Displacement << endl;
}

Ship::~Ship()
{
	cout << "Ship: " << Name << " was deleted. ID:" << this << endl;
	--Count;
}
