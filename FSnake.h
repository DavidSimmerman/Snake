#pragma once
#include <cstdlib>
#include <ctime>
#include <string>

class FSnake
{
public:
	void ResetGame();

	void SetDirection(int dir);
	int getDirection();

	int getBoard(int x, int y);
	char getLengthChar(int c);

	void Move();
	void Fruit();
	bool HasCollided();
	

private:
	int xSnake;
	int ySnake;
	int xFruit;
	int yFruit;
	int Length;
	int direction;
	int score;
	int Board[17][17];
	bool ActiveFruit;
	bool Colision;
};

