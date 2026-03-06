#include <iostream>
#include <string>

using namespace std;

// #define YELLOW		3  // main 밖에서 선언
// int Color = YELLOW;     // main 안에서 사용시 int Color = 3;

// cpu, 한 함수만 실행함
// cpu는 기억을 못함. main함수 진행 도중 함수가 호출되면 현재 위치를 저장하고 함수 실행
// 이때 함수와 main함수 구역은 서로 저장하는 공간이 달라서
// main함수에서의 변소룰 실행한 함수에서 사용할 수 없다
// 전역변수는 함수 내부에서 값을 변경하게 되면 발견이 힘들어져 자주 사용하지는 않음

#define CARDSIZE		52

string DrawShape(int CardNumber)
{
	int Shape = (CardNumber % 13 + 1);

	if (Shape == 11)
	{
		return "J";
	}
	else if (Shape == 12)
	{
		return "Q";
	}
	else if (Shape == 13)
	{
		return "K";
	}
	else if (Shape == 1)
	{
		return "A";
	}

	return to_string(Shape);
}

int main()
{
	// Swap
	//int A = 10;
	//int B = 30;
	//int Temp = A;
	//A = B;
	//B = Temp;

	int Cards[CARDSIZE] = { 0, };
	string CardType[4] = { "Heart", "Spade", "Diamond", "Clover" };
	for (int i = 0; i < CARDSIZE; i++)
	{
		Cards[i] = i;
	}

	srand((unsigned int)time(nullptr));
	// nullptr : C++에서 문법으로 사용되는 주소가 아무것도 아니라는 의미
	//int* C = 0;
	//C = nullptr;
	//cout << C << endl; // C의 주소 0000000000출력
	// shuffle
	// Random(난수) 두개 선택해서 교환
	// rand()
	for (int i = 0; i < CARDSIZE * 10; i++)
	{
		int FirstIndex = rand() % 52;
		int SecondIndex = rand() % 52;
		int Temp = Cards[FirstIndex];

		Cards[FirstIndex] = Cards[SecondIndex];
		Cards[SecondIndex] = Temp;
	}

	//Deal
	int ComputerCard[3];
	int PlayerCard[3];
	for (int i = 0; i < 3; i++)
	{
		ComputerCard[i] = Cards[i * 2];
		PlayerCard[i] = Cards[(i * 2) + 1];
	}

	int ComputerScore[3] = { 0, };
	int PlayerScore[3] = { 0, };
	for (int i = 0; i < 3; i++)
	{
		ComputerScore[i] = (ComputerCard[i] % 13 + 1) > 10 ? 10 : (ComputerCard[i] % 13 + 1);
		PlayerScore[i] = PlayerCard[i] % 13 + 1;
		PlayerScore[i] = PlayerScore[i] > 10 ? 10 : PlayerScore[i];
		// 조건식 ? 참실행문 : 거짓실행문
	}

	int TotalComputerScore = ComputerScore[0] + ComputerScore[1] + ComputerScore[2];
	int TotalPlayerScore = PlayerScore[0] + PlayerScore[1] + PlayerScore[2];

	// Draw
	if (TotalComputerScore > 21)
	{
		cout << "Player Win" << endl;
	}
	else if (TotalPlayerScore > 21)
	{
		cout << "Player Lose" << endl;
	}
	else if (TotalComputerScore > TotalPlayerScore)
	{
		cout << "Player Lose" << endl;
	}
	else
	{
		cout << "Player Win" << endl;
	}

	cout << "===========================" << endl;
	cout << "Computer Deck" << endl;
	for (int i = 0; i < 3; i++)
	{
		int CardTypeIndex = ComputerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << DrawShape(ComputerCard[i]) << endl;
	}
	cout << "Total : " << TotalComputerScore << endl;
	cout << "===========================" << endl;

	cout << "Player Deck" << endl;

	for (int i = 0; i < 3; i++)
	{
		int CardTypeIndex = PlayerCard[i] / 13;

		cout << CardType[CardTypeIndex] << " " << DrawShape(PlayerCard[i]) << endl;
	}
	cout << "Total : " << TotalPlayerScore << endl;
	cout << "===========================" << endl;

	return 0;
}