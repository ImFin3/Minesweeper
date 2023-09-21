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
	return position;
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
	return markedState;
}

void CCell::SetMarkedState(bool a_bMarkedState)
{
	*markedState = a_bMarkedState;
}

bool CCell::GetIsSelected(void)
{
	return *isSelected;
}

bool* CCell::GetIsSelectedPointer(void)
{
	return isSelected;
}

void CCell::SetIsSelected(bool a_bIsSelected)
{
	*isSelected = a_bIsSelected;
}

bool CCell::GetIsRevealed(void)
{
	return *isRevealed;
}

bool* CCell::GetIsRevealedPointer(void)
{
	return isRevealed;
}

void CCell::SetIsRevealed(bool a_bIsRevealed)
{
	*isRevealed = a_bIsRevealed;
}

CCell::CCell(CellType a_ctType, int a_iPosition)
{
	*type = a_ctType;
	*position = a_iPosition;
	*markedState = false;
	*isSelected = false;
	*isRevealed = false;
}

CCell::~CCell()
{
	delete type;
	type = nullptr;

	delete position;
	position = nullptr;

	delete markedState;
	markedState = nullptr;

	delete isSelected;
	isSelected = nullptr;

	delete isRevealed;
	isRevealed = nullptr;
}

