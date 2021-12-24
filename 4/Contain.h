#pragma once
#include "Ship.h"
#include <vector>
class Contain : public Ship
{
private:
	int count = 0;
	
	vector<Ship*> shipArray;

public:
	void Add();
	void Show();
	void Del();
	void LoadFromFile();
	void SaveToFile();

	~Contain();
};

