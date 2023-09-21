#ifndef CELL_H

#define CELL_H

#include "CellType.h"
#include "ProgrammSequence.h"

class CCell 
{
private:
	CellType* type = new CellType;
	int* position = new int;
	bool* markedState = new bool;
	bool* isSelected = new bool;
	bool* isRevealed = new bool;

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

	bool GetIsSelected(void);
	bool* GetIsSelectedPointer(void);
	void SetIsSelected(bool a_bIsSelected);

	bool GetIsRevealed(void);
	bool* GetIsRevealedPointer(void);
	void SetIsRevealed(bool a_bIsRevealed);


	#pragma endregion Getter/Setter


	#pragma region Methods

	//nothing here

	#pragma endregion Methods

	#pragma region Constructor

	CCell(CellType a_ctType, int a_iPosition);

	~CCell();

	#pragma endregion Constructor





};

#endif 

