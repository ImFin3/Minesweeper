#include "Cell.h"

CellType CCell::GetType(void)
{
	return type;
}

void CCell::SetType(CellType a_ctType)
{
	type = a_ctType;
}

int CCell::GetPosition(void)
{
	return position;
}

void CCell::SetPosition(int a_iPosition)
{
	position = a_iPosition;
}

bool CCell::GetMarkedState(void)
{
	return markedState;
}

void CCell::SetMarkedState(bool a_bMarkedState)
{
	markedState = a_bMarkedState;
}

bool CCell::GetIsSelected(void)
{
	return isSelected;
}

void CCell::SetIsSelected(bool a_bIsSelected)
{
	isSelected = a_bIsSelected;
}

bool CCell::GetIsRevealed(void)
{
	return isRevealed;
}

void CCell::SetIsRevealed(bool a_bIsRevealed)
{
	isRevealed = a_bIsRevealed;
}

CCell::CCell(CellType a_ctType, int a_iPosition)
{
	type = a_ctType;
	position = a_iPosition;
	markedState = false;
	isSelected = false;
	isRevealed = false;
}

CCell::~CCell()
{

}

