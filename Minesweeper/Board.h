#ifndef BOARD_H

#define BOARD_H

#include <iostream>
#include <vector>
#include "Cell.h"
#include "CellType.h"
#include <Windows.h>
#include <fcntl.h>
#include <io.h>

class CBoard 
{
private:
	std::vector<CCell> cellList;
	int width;
	int height;
	int mineCount;
	int listLength;
	
public:

	#pragma region Getter

	std::vector<CCell> GetCellList(void);
	int GetWidth(void);
	int GetHeight(void);
	int GetMineCount(void);
	int GetListLength(void);

	#pragma endregion Getter

	#pragma region Setter

	//not needed

	#pragma endregion Setter

	#pragma region Constructor

	CBoard();

	CBoard(int a_iWidth, int a_iHeight,  int a_iMineCount);

	#pragma endregion Constructor

	#pragma region Methods

	void InstantiateBoardValues(void);

	void CheckAndAssignBombAmountAt(int position);

	void Draw(void);

	#pragma endregion Methods

};

#endif