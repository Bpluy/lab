#include <iostream>
#include <string>

#include "Ship.h"

using namespace std;

int main()
{
	int actionCode, shipType, deleteID;
	bool isExit = false;

	Contain container;
	Ship* ship=new Ship();
	while (isExit != true)
	{
		cout << "Enter the action code: \n1 - Add \n2 - Show \n3 - Delete \n4 - Exit" << endl;
		cin >> actionCode;
		switch (actionCode)
		{
			case 1:
			{
				cout << "\nEnter the type of ship to be added: \n1 - Steamboat \n2 - Sailboat \n3 - Corvette" << endl;
				cin >> shipType;
				container.Add(shipType,ship);
				break;
			}
			case 2:
			{
				cout << "\nEnter the type of ship to be showed: \n1 - All \n2 - Steamboat \n3 - Sailboat \n4 - Corvette" << endl;
				cin >> shipType;
				container.Show(shipType);
				break;
			}
			case 3:
			{
				cout << "\nEnter the ID of ship to be deleted:" << endl;
				cin >> deleteID;
				container.Del(deleteID);
				break;
			}
			case 4:
			{
				isExit = true; break;
			}
			default:
			{
				cout << "\nError. Invalid value entered.\n" << endl;
				break;
			}
		}
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------------\n\n";
	}
	return 0;
}