#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "Ship.h"


Ship::Ship()
{
	this->Name = "";
	this->Type = "";
	this->Displacement = 0;
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
	cout << "Name: " << " Type: " << Type << Name << " Displacement: " << Displacement << endl;
}

string Ship::GetName() { return Name; }

string Ship::GetType() { return Type; }

int Ship::GetDisplacement() { return Displacement; }

void Ship::SetName(string Name) { this->Name = Name; }

void Ship::SetType(string Type) { this->Type = Type; }

void Ship::SetDisplacement(int Displacement) { this->Displacement = Displacement; }










Ship::~Ship() {}











class Steamboat : public Ship
{
private:
	int Power;

public:
	Steamboat();
	Steamboat(string Name, string Type, int Displacement, int Power);
	Steamboat(const Steamboat& original);

	void Show();
	int GetPower();
	void SetPower(int Power);

	~Steamboat();
};

class Sailboat : public Ship
{
	int MastsNumber;			//кол-во мачт

public:
	Sailboat();
	Sailboat(string Name, string Type, int Displacement, int MastsNumber);
	Sailboat(const Sailboat& original);

	void Show();

	int GetMNumber();
	void SetMNumber(int MastsNumber);

	~Sailboat();
};

class Corvette : public Ship
{
	int Complement;			// Ёкипаж (кол-во)

public:
	Corvette();
	Corvette(string Name, string Type, int Displacement, int Complement);
	Corvette(const Corvette& original);

	void Show();

	int GetComplement();
	void SetComplement(int Complement);

	~Corvette();
};

class Contain : public Ship
{
private:
	int count = 0;
	vector<Ship*>arr /*= { 0 }*/;
	//Ship** arr = new Ship*[1];
	//Ship** buf = new Ship*[2];

public:
	void Add(int,Ship*);
	void Show(int);
	void Del(int num);

	~Contain();
};







Steamboat::Steamboat() : Ship(), Power(0) {}

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
	cout << "Name: " << GetName() << " | Type: " << GetType() << " | Displacement: " << GetDisplacement() << " | Power: " << GetPower() << endl;
}

int Steamboat::GetPower() { return this->Power; }

void Steamboat::SetPower(int Power) { this->Power = Power; }



Sailboat::Sailboat() : Ship(), MastsNumber(0) {}

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
	cout << "Name: " << GetName() << " | Type: " << GetType() << " | Displacement: " << GetDisplacement() << " | Masts Number: " << GetMNumber() << endl;
}

int Sailboat::GetMNumber() { return this->MastsNumber; }

void Sailboat::SetMNumber(int MastsNumber) { this->MastsNumber = MastsNumber; }



Corvette::Corvette() : Ship(), Complement(0) {}

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
	cout << "Name: " << GetName() << " | Type: " << GetType() << " | Displacement: " << GetDisplacement() << " | Complement: " << GetComplement() << endl;
}

int Corvette::GetComplement() { return this->Complement; }

void Corvette::SetComplement(int Complement) { this->Complement = Complement; }







Steamboat::~Steamboat() {}

Sailboat::~Sailboat() {}

Corvette::~Corvette() {}

void Contain::Add(int reqType,Ship* ship)
{
	string Names[7] = { "Arizona","Flying Dutchman","Black Pearl","Silent Mary","Queen Anne's Revenge","HMS Dauntless","Dying Gull" };
	srand(time(0));
	string name_;
	int displacement_, power_, mNumber_, complement_, errorFlag = 0, wayFlag;
	switch (reqType)
	{
	case 1:
	{
		cout << "\nChoose the way to fill in the data about the ship: \n1 - manually \n2 - automatically" << endl;
		cin >> wayFlag;
		switch (wayFlag)
		{
		case 1:
		{
			cout << "\nEnter a Name of ship:" << endl;
			cin >> name_;
			cout << "\nEnter a displacement for " << name_ << endl;
			cin >> displacement_;
			cout << "\nEnter a power for " << name_ << endl;
			cin >> power_;
			ship = new Steamboat(name_, "Steamboat", displacement_, power_); 
			break;
		}
		default:
		{
			ship = new Steamboat(Names[rand() % 7], "Steamboat", rand() % 2500, rand() % 25000);
			break;
		}
		}
		break;
	}
	case 2:
	{
		cout << "\nChoose the way to fill in the data about the ship: \n1 - manually \n2 - automatically" << endl;
		cin >> wayFlag;
		switch (wayFlag)
		{
		case 1:
		{
			cout << "\nEnter a Name of ship:" << endl;
			cin >> name_;
			cout << "\nEnter a displacement for " << name_ << endl;
			cin >> displacement_;
			cout << "\nEnter a masts number for " << name_ << endl;
			cin >> mNumber_;
			ship = new Sailboat(name_, "Sailboat", displacement_, mNumber_);
			break;
		}
		default:
		{
			ship = new Sailboat(Names[rand() % 7], "Sailboat", rand() % 2500, rand() % 3 + 1);
			break;
		}
		}
		break;
	}
	case 3:
	{
		cout << "\nChoose the way to fill in the data about the ship: \n1 - manually \n2 - automatically" << endl;
		cin >> wayFlag;
		switch (wayFlag)
		{
		case 1:
		{
			cout << "\nEnter a Name of ship:" << endl;
			cin >> name_;
			cout << "\nEnter a displacement for " << name_ << endl;
			cin >> displacement_;
			cout << "\nEnter a complement for " << name_ << endl;
			cin >> complement_;
			ship = new Corvette(name_, "Corvette", displacement_, complement_);
			break;
		}
		default:
		{
			ship = new Corvette(Names[rand() % 7], "Corvette", rand() % 2500, rand() % 200 + 10);
			break;
		}
		}
		break;
	}
	default:
	{
		cout << "\nError. Invalid value entered.\n" << endl;
		errorFlag++;
		break;
	}
	}
	if (errorFlag == 0)
	{
		/*arr[count] = ship;*/
		arr.push_back(ship);
		cout << "\nNow you have entered:" << endl;
		arr[count]->Show();
		++count;
		/*for (int i = 0; i < count; i++)
			buf[i] = arr[i];
		arr = buf;
		buf = new Ship * [count + 1];*/
	}
}

void Contain::Show(int reqType)
{
	switch (reqType)
	{
	case 1: 
		{
		for (int i = 0; i < count; i++)
		{
			cout << "ID: " << i << " | ";
			arr[i]->Show();
		}
			break;
		}
	case 2:
		{
			for (int i = 0; i < count; i++)
			{
				if (arr[i]->GetType() == "Steamboat")
				{
					cout << "ID: " << i << " | ";
					arr[i]->Show();
				}
			}
			break;
		}
	case 3:
		{
			for (int i = 0; i < count; i++)
			{
				if (arr[i]->GetType() == "Sailboat") 
				{
					cout << "ID: " << i << " | ";
					arr[i]->Show();
				}
			}
			break;
		}
	case 4:
		{
			for (int i = 0; i < count; i++)
			{
				if (arr[i]->GetType() == "Corvette")
				{
					cout << "ID: " << i << " | ";
					arr[i]->Show();
				}
			}
			break;
		}
	default:
		{
		cout << "Error. Invalid value entered.\n" << endl;
		break;
		}
	}
	if (count == 0)cout << "There is no data on ships. Use the add function and try again later.\n" << endl;
}

void Contain::Del(int num)
{
	if (num >= count)
		cout << "Error. The entered number exceeds the maximum possible - " << count - 1 << "\n" << endl;
	else
	{
		auto iter = arr.begin();
		arr.erase(iter+num);
		count--;
	}
}

Contain::~Contain()
{
	arr.clear();
}


