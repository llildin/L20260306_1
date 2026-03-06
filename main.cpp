#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int Player[3] = { 0, };
	int Computer[3] = { 0, };
	int PlayerSum = 0;
	int ComputerSum = 0;

	cout << "Player : ";

	for (int i = 0; i < 3; i++)
	{
		Player[i] = (rand() % 12) +1;

		if (Player[i] == 10)
		{
			cout << "J ";
			Player[i] = 10;
		}
		else if (Player[i] == 11)
		{
			cout << "Q ";
			Player[i] = 10;
		}
		else if (Player[i] == 12)
		{
			cout << "K ";
			Player[i] = 10;
		}
		else
		{
			cout << Player[i] << " ";
		}

		PlayerSum += Player[i];
	}

	cout << endl << "Player Sum : " << PlayerSum << endl;
	cout << "Computer : ";

	for (int i = 0; i < 3; i++)
	{
		Computer[i] = (rand() % 12) + 1;

		if (Computer[i] == 10)
		{
			cout << "J ";
			Computer[i] = 10;
		}
		else if (Computer[i] == 11)
		{
			cout << "Q ";
			Computer[i] = 10;
		}
		else if (Computer[i] == 12)
		{
			cout << "K ";
			Computer[i] = 10;
		}
		else
		{
			cout << Computer[i] << " ";
		}

		ComputerSum += Computer[i];
	}

	cout << endl << "Computer Sum : " << ComputerSum << endl;

	if (ComputerSum > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (PlayerSum > 21 || PlayerSum < ComputerSum)
	{
		cout << "Player Lose" << endl;
	}
	else if (PlayerSum >= ComputerSum)
	{
		cout << "Player Win" << endl;
	}

	return 0;
}