#include "Cell.h"

CellType CCell::GetType(void)
{
	return *type;
}

CellType* CCell::GetTypePointer(void)
{
	return this->type;
}

void CCell::SetType(CellType a_ctType)
{
	*type = a_ctType;
}

int CCell::GetPosition(void)
{
	return *position;
}

int* CCell::GetPositionPointer(void)
{
	return this->position;
}

void CCell::SetPosition(int a_iPosition)
{
	*position = a_iPosition;
}

bool CCell::GetMarkedState(void)
{
	return *markedState;
}

bool* CCell::GetMarkedStatePointer(void)
{
	return this->markedState;
}

void CCell::SetMarkedState(bool a_bMarkedState)
{
	*markedState = a_bMarkedState;
}

CCell::CCell(CellType a_ctType, int a_iPosition)
{
	*type = a_ctType;
	*position = a_iPosition;
	*markedState = false;
}
