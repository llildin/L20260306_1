#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int Card[4][12] =
	{ {1,2,3,4,5,6,7,8,9,10,11,12},
		{1,2,3,4,5,6,7,8,9,10,11,12},
		{1,2,3,4,5,6,7,8,9,10,11,12},
		{1,2,3,4,5,6,7,8,9,10,11,12}
	};
	int Player[3];
	int Computer[3];
	int PlayerSum = 0;
	int ComputerSum = 0;
	int CardShape = 0;
	int CardNum = 0;

	cout << "Player : ";

	for (int i = 0; i < 3; i++)
	{
		for (; ;)
		{
			CardShape = (rand() % 4);
			CardNum = (rand() % 12);
			if (Card[CardShape][CardNum] != 0)
			{
				Player[i] = Card[CardShape][CardNum];
				Card[CardShape][CardNum] = 0;
				break;
			}
		}

		if (CardShape == 0)
		{
			cout << "스페이드";
		}
		else if (CardShape == 1)
		{
			cout << "클로버";
		}
		else if (CardShape == 2)
		{
			cout << "하트";
		}
		else if (CardShape == 3)
		{
			cout << "다이다";
		}

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
		for (; ;)
		{
			CardShape = (rand() % 4);
			CardNum = (rand() % 12);
			if (Card[CardShape][CardNum] != 0)
			{
				Computer[i] = Card[CardShape][CardNum];
				Card[CardShape][CardNum] = 0;
				break;
			}
		}

		if (CardShape == 0)
		{
			cout << "스페이드";
		}
		else if (CardShape == 1)
		{
			cout << "클로버";
		}
		else if (CardShape == 2)
		{
			cout << "하트";
		}
		else if (CardShape == 3)
		{
			cout << "다이다";
		}

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