#include <iostream>
#include <string>

#define add 1
#define show 2
#define delete 3
#define exit 4

#include "Contain.h"

using namespace std;

int main()
{
	int actionCode;
	bool isExit = false;

	Contain container;
	container.LoadFromFile();
	while (isExit != true)
	{
		cout << "Enter the action code: \n1 - Add \n2 - Show \n3 - Delete \n4 - Exit" << endl;
		cin >> actionCode;
		switch (actionCode)
		{
			case add:
			{
				container.Add();
				break;
			}
			case show:
			{
				container.Show();
				break;
			}
			case delete:
			{
				container.Del();
				break;
			}
			case exit:
			{
				isExit = true; break;
			}
			default:
			{
				cout << "\nError. Invalid value entered.\n" << endl;
				actionCode = 5;
				break;
			}
		}
		cout << "\n\n-----------------------------------------------------------------------------------------------------------------------\n\n";
	}
	container.SaveToFile();
	return 0;
}