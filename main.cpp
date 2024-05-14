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

void Input() // Input값을 반복문을 통해 함수로 지정할거야
{
	Key = _getch(); // 사용자가 입력하는 키값을 즉시 읽을거임
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
		IsRunning = false; //27은 ESC키를 뜻하며 esc키를 눌렀을 때 정지하겠다.
	}
}

void Render()
{
	system("cls");//콘솔명령어를 지우기 위해 사용함

	for (int Y = 0; Y < 10; Y++)
	{
		for (int X = 0; X < 10; X++)
		{

			if (PlayerX == X && PlayerY == Y) //조건문을 통해 플레이어의 위치를 표시하시 위해 사용 &&는 X,Y의 조건이 참일때 참을 반환 
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