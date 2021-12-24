#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <fstream>

#include "Contain.h"
#include "Corvette.h"
#include "Sailboat.h"
#include "Steamboat.h"
#include "nlohmann/json.hpp"

Ship* ship;
int shipType;

void Contain::Add()
{
	cout << "\nEnter the type of ship to be added: \n1 - Steamboat \n2 - Sailboat \n3 - Corvette" << endl;
	cin >> shipType;	
	int errorFlag = 0, wayFlag;
	switch (shipType)
	{
	case 1:
	{
		cout << "\nChoose the way to fill in the data about the ship: \n1 - manually \n2 - automatically" << endl;
		cin >> wayFlag;
		switch (wayFlag)
		{
		case 1:
		{
			ship = new Steamboat("Steamboat");
			break;
		}
		default:
		{
			ship = new Steamboat("Steamboat", true);
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
			ship = new Sailboat("Sailboat");
			break;
		}
		default:
		{
			ship = new Sailboat("Sailboat",true);
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
			ship = new Corvette("Corvette");
			break;
		}
		default:
		{
			ship = new Corvette("Corvette",true);
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
		shipArray.push_back(ship);
		cout << "\nNow you have entered:" << endl;
		shipArray[count]->Show();
		++count;
	}
}

void Contain::Show()
{
	cout << "\nEnter the type of ship to be showed: \n1 - All \n2 - Steamboat \n3 - Sailboat \n4 - Corvette" << endl;
	cin >> shipType;
	switch (shipType)
	{
	case 1:
	{
		for (int i = 0; i < count; i++)
		{
			cout << "ID: " << i << " | ";
			shipArray[i]->Show();
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < count; i++)
		{
			if (shipArray[i]->GetType() == "Steamboat")
			{
				cout << "ID: " << i << " | ";
				shipArray[i]->Show();
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < count; i++)
		{
			if (shipArray[i]->GetType() == "Sailboat")
			{
				cout << "ID: " << i << " | ";
				shipArray[i]->Show();
			}
		}
		break;
	}
	case 4:
	{
		for (int i = 0; i < count; i++)
		{
			if (shipArray[i]->GetType() == "Corvette")
			{
				cout << "ID: " << i << " | ";
				shipArray[i]->Show();
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

void Contain::Del()
{
	int deleteID;
	cout << "\nEnter the ID of ship to be deleted:" << endl;
	cin >> deleteID;
	if (deleteID >= count)
		cout << "\nError. The entered number exceeds the maximum possible - " << count - 1 << "\n" << endl;
	else
	{
		auto iter = shipArray.begin();
		shipArray.erase(iter + deleteID);
		count--;
	}
}

void Contain::LoadFromFile()
{	
	ifstream in;
	Corvette* ship = new Corvette();
	Corvette* corvette = new Corvette();
	Sailboat* sailboat = new Sailboat();
	Steamboat* steamboat = new Steamboat();
	in.open("config.txt");
	while (in.read((char*)ship, sizeof(*(Corvette*)ship)))
	{
		if (ship->GetType() == "Sailboat")
		{
			sailboat->SetName(ship->GetName());
			sailboat->SetType(ship->GetType());
			sailboat->SetDisplacement(ship->GetDisplacement());
			sailboat->SetMNumber(ship->GetComplement());
			shipArray.push_back(sailboat);
			++count;
			sailboat = new Sailboat();
		}
		else
		{
			if (ship->GetType() == "Steamboat")
			{
				steamboat->SetName(ship->GetName());
				steamboat->SetType(ship->GetType());
				steamboat->SetDisplacement(ship->GetDisplacement());
				steamboat->SetPower(ship->GetComplement());
				shipArray.push_back(steamboat);
				++count;
				steamboat = new Steamboat();
			}
			else
			{
				corvette->SetName(ship->GetName());
				corvette->SetType(ship->GetType());
				corvette->SetDisplacement(ship->GetDisplacement());
				corvette->SetComplement(ship->GetComplement());
				shipArray.push_back(corvette);
				++count;
			}
		}
		in.read((char*)ship, sizeof(char));
		ship = new Corvette();
	}
	in.close();
}

void Contain::SaveToFile()
{
	ofstream out;
	Ship* ship;
	out.open("config.txt");
	out << "";
	out.close();
	out.open("config.txt", ofstream::app);
	for (int i = 0; i < shipArray.size(); i++)
	{
		ship = shipArray[i];
		out.write((char*)ship, sizeof(*(Corvette*)ship));
		out.put('\n');
	}
	out.close();	
}

Contain::~Contain()
{
	shipArray.clear();
}