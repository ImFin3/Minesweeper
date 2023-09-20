#ifndef CELL_H
#define CELL_H

#include "CellType.h"

class CCell
{
private:
	CellType type = CellType::CELLTYPE_NONE;
	int position;

public:
#pragma region Getter/Setter

	CellType GetType(void);
	void SetType(CellType a_type);

	int GetPosition(void);
	void SetPosition(int a_position);

#pragma endregion Getter/Setter

};

#endif 





