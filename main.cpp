#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int PlayerX = 1;
int PlayerY = 1;
char PlayerShape = 'P';

int MonsterX = 5;
int MonsterY = 5;
int RandMove = rand() % 4;
char MonsterShape = 'M';

int GoalX = 8;
int GoalY = 8;
char GoalShape = 'G';

char FloorShape = ' ';
char WallShape = '*';

int Key = 0;
int World[10][10] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};

bool IsRunning = true;

void Input() // Input���� �ݺ����� ���� �Լ��� �����Ұž�
{
	Key = _getch(); // ����ڰ� �Է��ϴ� Ű���� ��� ��������
}

void Tick()
{
	if (Key == 'w' && PlayerY > 0 && World[PlayerY - 1][PlayerX] != 1)
	{
		PlayerY--;
	}

	if (Key == 's' && PlayerY < 9 && World[PlayerY + 1][PlayerX] != 1)
	{
		PlayerY++;
	}

	if (Key == 'a' && PlayerX > 0 && World[PlayerY][PlayerX - 1] != 1)
	{
		PlayerX--;
	}

	if (Key == 'd' && PlayerX < 9 && World[PlayerY][PlayerX + 1] != 1)
	{
		PlayerX++;
	}
	RandMove = rand() % 4;
	if (RandMove == 0 && MonsterY > 0 && World[MonsterY - 1][MonsterX] != 1)
	{
		MonsterY--;
	}
	else if (RandMove == 1 && MonsterY < 9 && World[MonsterY + 1][MonsterX] != 1)
	{
		MonsterY++;
	}
	else if (RandMove == 2 && MonsterX > 0 && World[MonsterY][MonsterX - 1] != 1)
	{
		MonsterX--;
	}
	else if (RandMove == 3 && MonsterX < 9 && World[MonsterY][MonsterX + 1] != 1)
	{
		MonsterX++;
	}

	if (Key == 27)
	{
		IsRunning = false; //27�� ESCŰ�� ���ϸ� escŰ�� ������ �� �����ϰڴ�.
	}
}

void Render()
{
	system("cls");//�ָܼ�ɾ ����� ���� �����

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{

			if (PlayerX == X && PlayerY == Y) //���ǹ��� ���� �÷��̾��� ��ġ�� ǥ���Ͻ� ���� ��� &&�� X,Y�� ������ ���϶� ���� ��ȯ 
			{
				cout << PlayerShape;
			}
			else if (MonsterX == X && MonsterY == Y)
			{
				cout << MonsterShape;
			}
			else if (GoalX == X && GoalY == Y)
			{
				cout << GoalShape;
			}
			else if (World[Y][X] == 0)
			{
				cout << FloorShape;
			}
			else if (World[Y][X] == 1)
			{
				cout << WallShape;
			}

		}
		cout << endl;
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	while (IsRunning)
	{
		Input();

		Tick();

		Render();
	}

	return 0;
}