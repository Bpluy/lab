#include <iostream>
#include <random>
#include <iomanip>
#include <bitset>

#define Num 10

using namespace std;
int tetrchanger(int a)
{
	int b = 0;
	for (int i = 7; i >= 0; i--)
		b += (((a << (28 - 4 * i)) >> 28) & 15) << (28 - 4 * i);
	return b;
}

int main()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(-2147483648, 2147483647);

	int Input[Num],Output[Num];
	for (int i = 0; i < Num; i++)
	{
		Input[i] = dist(gen);
		if (Input[i] % 2 == 0)
			Output[i] = tetrchanger(Input[i]); 
		else 
			Output[i] = Input[i];
		cout << "Input:  DEC " << dec << setw(11) << Input[i] << " | HEX " << hex << setw(8) << Input[i] << " | BYTE " << bitset<32>(Input[i]) << "\n";
		cout << "Output: DEC " << dec << setw(11) << Output[i] << " | HEX " << hex << setw(8) << Output[i] << " | BYTE " << bitset<32>(Output[i]) << "\n";
		cout << "------------------------------------------------------------------------------\n";
	}
}
