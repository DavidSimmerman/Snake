#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "FSnake.h"

FSnake snGame;

enum direction { Up, Down, Left, Right };

void StartMenu();
void PlayGame();
void PrintScreen();
void PrintClear();
void UserInput();
bool GameOver();

int main()
{
	do
	{
		StartMenu();
		PlayGame();
	} while (!GameOver());
}

void StartMenu()
{
	system("cls");
	snGame.ResetGame();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool MRR = false;

	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 18; x++)
		{
			if (x == 17) { std::cout << std::endl; }
			else if (y == 8)
			{
				if (!MRR)
				{
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					std::cout << (char)254u << "     ";
					SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					std::cout << "Press Enter To Start      ";
					SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					std::cout << (char)254u << " ";
					MRR = true;
				}
			}
			else if ((x == 0 || x == 16) || (y == 0 || y == 16))
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				std::cout << (char)254u << " ";
			}
			else
			{
				std::cout << "  ";
			}
		}
	}
	std::cin.ignore();
}

void PlayGame()
{
	snGame.Fruit();
	do
	{
		snGame.Fruit();
		UserInput();
		PrintScreen();
		UserInput();
		if (!snGame.HasCollided()) { Sleep(500); }
		UserInput();
		if (snGame.HasCollided()) { break; }
		else { snGame.Move(); }
	} while (true);
}

void PrintScreen()
{
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 18; x++)
		{
			if (x == 17) { std::cout << std::endl; }
			else if ((x == 0 || x == 16) || (y == 0 || y == 16))
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				std::cout << (char)254u << " ";
			}
			else if (snGame.getBoard(x, y) > 0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << (char)254u << " ";
			}
			else if (snGame.getBoard(x, y) == -1)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << (char)162u << " ";
			}
			else
			{
				std::cout << "  ";
			}
		}
	}
}

void PrintClear()
{
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 18; x++)
		{
			if (x == 17) { std::cout << std::endl; }
			else if ((x == 0 || x == 16) || (y == 0 || y == 16))
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				std::cout << (char)254u << " ";
			}
			else if (snGame.getBoard(x, y) == -1)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << (char)162u << " ";
			}
			else
			{
				std::cout << "  ";
			}
		}
	}
	Sleep(150);
	PrintScreen();
}

void UserInput()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (snGame.getDirection() != direction::Down)
			{
				snGame.SetDirection(direction::Up);
			}
			break;
		case 's':
			if (snGame.getDirection() != direction::Up)
			{
				snGame.SetDirection(direction::Down);
			}
			break;
		case 'a':
			if (snGame.getDirection() != direction::Right)
			{
				snGame.SetDirection(direction::Left);
			}
			break;
		case 'd':
			if (snGame.getDirection() != direction::Left)
			{
				snGame.SetDirection(direction::Right);
			}
			break;
		}
	}
}

bool GameOver()
{
	PrintClear();
	PrintClear();
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int y = 0; y < 17; y++)
	{
		for (int x = 0; x < 18; x++)
		{
			if (x == 17) { std::cout << std::endl; }
			else if (y == 5 && x >= 6 && x <= 10)
			{
				switch (x)
				{
				case 6:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "Ga";
					break;
				case 7:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "me";
					break;
				case 8:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << " O";
					break;
				case 9:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "ve";
					break;
				case 10:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "r!";
					break;
				}
			}
			else if (y == 6 && x >= 6 && x <= 10)
			{
				switch (x)
				{
				case 6:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "Sc";
					break;
				case 7:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "or";
					break;
				case 8:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "e:";
					break;
				case 9:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << " " << snGame.getLengthChar(1);
					break;
				case 10:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << snGame.getLengthChar(2) << snGame.getLengthChar(3);
					break;
				}
			}
			else if (y == 8 && x >= 5 && x <= 11)
			{
				switch (x)
				{
				case 5:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "Pr";
					break;
				case 6:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "es";
					break;
				case 7:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "s ";
					break;
				case 8:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "En";
					break;
				case 9:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "te";
					break;
				case 10:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "r ";
					break;
				case 11:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "to";
					break;
				}
			}
			else if (y == 9 && x >= 6 && x <= 10)
			{
				switch (x)
				{
				case 6:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "Pl";
					break;
				case 7:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "ay";
					break;
				case 8:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << " A";
					break;
				case 9:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "ga";
					break;
				case 10:
					SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
					std::cout << "in";
					break;
				}
			}
			else if ((x == 0 || x == 16) || (y == 0 || y == 16))
			{
				SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				std::cout << (char)254u << " ";
			}
			else if (snGame.getBoard(x, y) > 0)
			{
				SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				std::cout << (char)254u << " ";
			}
			else if (snGame.getBoard(x, y) == -1)
			{
				SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
				std::cout << (char)162u << " ";
			}
			else
			{
				std::cout << "  ";
			}
		}
	}

	std::cin.ignore();
	return false;
}
