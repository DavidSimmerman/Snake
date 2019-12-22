#include "FSnake.h"

enum direction {Up, Down, Left, Right};

void FSnake::ResetGame()
{
	xSnake = 8;
	ySnake = 8;
	Length = 3;
	direction = direction::Up;
	Colision = false;
	ActiveFruit = false;
	
	for (int x = 1; x < 16; x++)
	{
		for (int y = 1; y < 16; y++)
		{
			Board[x][y] = 0;
		}
	}

	Board[8][8] = Length;
}

void FSnake::SetDirection(int dir) { direction = dir; }

int FSnake::getDirection() { return direction; }

int FSnake::getBoard(int x, int y) { return Board[x][y]; }

char FSnake::getLengthChar(int c)
{	
	score = Length + 997;
	std::string sScore = std::to_string(score);
	return sScore[c];
}

void FSnake::Move()
{
	switch (direction)
	{
	case direction::Up:
		ySnake -= 1;
		if (Board[xSnake][ySnake] > 0 || (xSnake < 1 || xSnake > 15) ||  (ySnake < 1 || ySnake > 15)) { Colision = true; }
		break;
	case direction::Down:
		ySnake += 1;
		if (Board[xSnake][ySnake] > 0 || (xSnake < 1 || xSnake > 15) || (ySnake < 1 || ySnake > 15)) { Colision = true; }
		break;
	case direction::Left:
		xSnake -= 1;
		if (Board[xSnake][ySnake] > 0 || (xSnake < 1 || xSnake > 15) || (ySnake < 1 || ySnake > 15)) { Colision = true; }
		break;
	case direction::Right:
		xSnake += 1;
		if (Board[xSnake][ySnake] > 0 || (xSnake < 1 || xSnake > 15) || (ySnake < 1 || ySnake > 15)) { Colision = true; }
		break;
	}
	if (!Colision)
	{
		for (int x = 1; x < 16; x++)
		{
			for (int y = 1; y < 16; y++)
			{
				if (Board[x][y] > 0) { Board[x][y]--; }
			}
		}
	}
	if (!Colision) { Board[xSnake][ySnake] = Length; }
}

void FSnake::Fruit()
{
	srand(time(0));
	if (ActiveFruit && xSnake == xFruit && ySnake == yFruit)
	{
		Length++;
		for (int x = 1; x < 16; x++)
		{
			for (int y = 1; y < 16; y++)
			{ 
				if (Board[x][y] > 0)
				{
					Board[x][y]++;
				}
			}
		}
		do
		{
			xFruit = (rand() % 15) + 1;
			yFruit = (rand() % 15) + 1;
		} while (Board[xFruit][yFruit] != 0);
		Board[xFruit][yFruit] = -1;
		ActiveFruit = true;
	}
	else if (!ActiveFruit)
	{
		
		xFruit = (rand() % 15) + 1;
		yFruit = (rand() % 15) + 1;
		Board[xFruit][yFruit] = -1;
		ActiveFruit = true;
	}
}

bool FSnake::HasCollided() { return Colision; }
