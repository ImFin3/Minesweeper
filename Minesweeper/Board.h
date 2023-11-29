#ifndef BOARD_H

#define BOARD_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "CellType.h"
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "GameState.h"
#include <ctime>

class CBoard 
{
private:
	std::vector<CCell> cellList;
	int currentPosition;
	int width;
	int height;
	int mineCount;
	int listLength;
	GameState gameState;

	
public:
	#pragma region Getter

	std::vector<CCell> GetCellList(void);
	int GetCurrentPosition(void);
	int GetWidth(void);
	int GetHeight(void);
	int GetMineCount(void);
	int GetListLength(void);
	GameState GetGameState(void);

	#pragma endregion Getter

	#pragma region Setter

	//not needed

	#pragma endregion Setter

	#pragma region Constructor

	CBoard();

	CBoard(const int &a_iWidth, const int &a_iHeight, const int &a_iMineCount);

	#pragma endregion Constructor

	#pragma region Methods

private:
	void InstantiateBoardValues(void);

	void CheckAndAssignBombAmountAt(const int &position);

	void WonScreen(void);
	void LostScreen(void);

public:
	void Draw(void);

	void WinCheck(void);
	void EndScreen(void);

	void GoUp(void);
	void GoLeft(void);
	void GoDown(void);
	void GoRight(void);

	void Reveal(const int &position);
	void Mark(void);

	#pragma endregion Methods

};

#endif