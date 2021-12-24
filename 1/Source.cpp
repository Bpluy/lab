#include <iostream>
#include <random>
#include <iomanip>
#include <bitset>
#include <conio.h>

//30.«еркально помен€ть местами тетрады четных чисел.

using namespace std;

int ChangeTetrads(int a)
{
	int b = 0;
	int mask = 0x0f;
	for (int i = 7; i >= 0; i--)
		b += (((a << (28 - 4 * i)) >> 28) & mask) << (28 - 4 * i);
	return b;
}

int GetRandom()
{
	static random_device rd;
	static mt19937 gen(rd());
	static uniform_int_distribution<> dist(-2147483648, 2147483647);
	return dist(gen);
}

void Output(int* MasInput,int* MasOutput,int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "Input:  DEC " 
			 << dec << setw(11) << MasInput[i] << " | HEX " 
			 << hex << setw(8) << MasInput[i] << " | BYTE " 
			 << bitset<32>(MasInput[i]) << "\n"
			 << "Output: DEC " 
			 << dec << setw(11) << MasOutput[i] << " | HEX " 
			 << hex << setw(8) << MasOutput[i] << " | BYTE " 
			 << bitset<32>(MasOutput[i]) << "\n"
			 << "------------------------------------------------------------------------------\n";
	}
}

int main()
{
	int num;
	cout << "Type numbers for processing\n";
	cin >> num;

	int* MasInput=new int[num];
	int* MasOutput=new int[num];

	for (int i = 0; i < num; i++)
	{
		MasInput[i] = GetRandom();
		if ((MasInput[i] & 1) == 0)
			MasOutput[i] = ChangeTetrads(MasInput[i]);
		else 
			MasOutput[i] = MasInput[i];
	}
	Output(MasInput, MasOutput,num);
	delete[] MasInput;
	delete[] MasOutput;
}
