#include "Cell.h"

CellType CCell::GetType(void)
{
	return type;
}

void CCell::SetType(const CellType &a_ctType)
{
	type = a_ctType;
}

//int CCell::GetPosition(void)
//{
//	return position;
//}
//
//void CCell::SetPosition(int a_iPosition)
//{
//	position = a_iPosition;
//}

bool CCell::GetMarkedState(void)
{
	return markedState;
}

void CCell::SetMarkedState(const bool &a_bMarkedState)
{
	markedState = a_bMarkedState;
}

bool CCell::GetIsSelected(void)
{
	return isSelected;
}

void CCell::SetIsSelected(const bool &a_bIsSelected)
{
	isSelected = a_bIsSelected;
}

bool CCell::GetIsRevealed(void)
{
	return isRevealed;
}

void CCell::SetIsRevealed(const bool &a_bIsRevealed)
{
	isRevealed = a_bIsRevealed;
}

CCell::CCell(const CellType &a_ctType)
{
	type = a_ctType;
	markedState = false;
	isSelected = false;
	isRevealed = false;
}



