#include <iostream>
#include <string>

#include "Ship.h"

using namespace std;

int main()
{
	Ship Battleship("HMS Sovereign of the Seas", 1522, "Sailing");
	Ship Aerocarrier("Nimitz", 97000, "Reactive");
	
	Ship Aerocarrier_(Aerocarrier);
	Aerocarrier_.SetDisplacement(106300);
	
	Ship* NoNameShip = new Ship();
	
	int lenght = Ship::GetCount();
	cout << "Number of objects: " << lenght << endl;
	
	Ship* Ships[100];
	Ships[0] = &Battleship;
	Ships[1] = &Aerocarrier;
	Ships[2] = &Aerocarrier_;
	Ships[3] = NoNameShip;
	for (int i = 0; i < lenght; ++i)
	{
		cout << endl;
		Ships[i]->Show();
		cout << endl;
	}

	NoNameShip->~Ship();
	return 0;
}