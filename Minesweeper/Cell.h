#ifndef CELL_H

#define CELL_H

#include "CellType.h"

class CCell
{
private:
	CellType* type = new CellType;
	int* position = new int;
	bool* markedState = new bool;

public:


	#pragma region Getter/Setter


	CellType GetType(void);
	CellType* GetTypePointer(void);
	void SetType(CellType a_ctType);

	int GetPosition(void);
	int* GetPositionPointer(void);
	void SetPosition(int a_iPosition);

	bool GetMarkedState(void);
	bool* GetMarkedStatePointer(void);
	void SetMarkedState(bool a_bMarkedState);


	#pragma endregion Getter/Setter


	#pragma region Methods

	//nothing here

	#pragma endregion Methods

	#pragma region Constructor

	CCell(CellType a_ctType, int a_iPosition);

	#pragma endregion Constructor


};

#endif 

