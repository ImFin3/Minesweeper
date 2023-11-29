#ifndef CELL_H

#define CELL_H

#include "CellType.h"
#include "ProgrammSequence.h"

class CCell 
{
private:
	CellType type;
	bool markedState;
	bool isSelected;
	bool isRevealed;

public:

	#pragma region Getter/Setter


	CellType GetType(void);
	void SetType(const CellType &a_ctType);

	bool GetMarkedState(void);
	void SetMarkedState(const bool &a_bMarkedState);

	bool GetIsSelected(void);
	void SetIsSelected(const bool &a_bIsSelected);

	bool GetIsRevealed(void);
	void SetIsRevealed(const bool &a_bIsRevealed);


	#pragma endregion Getter/Setter


	#pragma region Methods

	//nothing here

	#pragma endregion Methods

	#pragma region Constructor

	CCell(const CellType &a_ctType);

	#pragma endregion Constructor





};

#endif 

