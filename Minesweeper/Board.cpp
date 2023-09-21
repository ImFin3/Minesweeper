#include "Board.h"

std::vector<CCell*>* CBoard::GetCellList(void)
{
    return this->cellList;
}

int* CBoard::GetWidth(void)
{
    return this->width;
}

int* CBoard::GetHeight(void)
{
    return this->height;
}

int* CBoard::GetMineCount(void)
{
    return this->mineCount;
}

int* CBoard::GetListLength(void)
{
    return this->listLength;
}

CBoard::CBoard(int a_iWidth, int a_iHeight, int a_iMineCount)
{
    *width = a_iWidth;
    *height = a_iHeight;
    *mineCount = a_iMineCount;
    *listLength = a_iWidth * a_iHeight;

    InstantiateBoardValues();

}

void CBoard::InstantiateBoardValues(void)
{
    int count = 0;
    cellList->clear();

    //fill list with values
    while (count < *listLength) 
    {
        cellList->push_back(new CCell(CellType::CELLTYPE_EMPTY, count));

        count++;
    }

    count = 0;

    //change random list elements to mines
    while (count < *mineCount) 
    {
        int minePos = rand() % *listLength + 1;

        if (cellList->at(minePos)->GetType() == CellType::CELLTYPE_EMPTY) 
        {
            cellList->at(minePos)->SetType(CellType::CELLTYPE_MINE);

            count++;
        }
    }

    count = 0;

    //set each CellType in the list
    while (count < *listLength) 
    {
        CheckAndAssignBombAmountAt(count);
    }
}

void CBoard::CheckAndAssignBombAmountAt(int position)
{
    int bombAmount = 0;

    if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) return;


    //check for how many bombs are around
    else 
    {
        //top left 
        if (position + *width - 1 <= *listLength) 
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //top mid
        if (position + *width <= *listLength)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //top right
        if (position + *width + 1 <= *listLength)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //left
        if(position - 1 >= 0)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //right
        if (position + 1 <= *listLength)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //bot left
        if (position - *width - 1 >= 0)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //bot mid
        if (position - *width >= 0)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //bot right
        if (position - *width + 1 >= 0)
        {
            if (cellList->at(position)->GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

    }

    switch (bombAmount)
    {
    case 0:
        cellList->at(position)->SetType(CellType::CELLTYPE_EMPTY);
        break;
    case 1:
        cellList->at(position)->SetType(CellType::CELLTYPE_1);
        break;
    case 2:
        cellList->at(position)->SetType(CellType::CELLTYPE_2);
        break;
    case 3:
        cellList->at(position)->SetType(CellType::CELLTYPE_3);
        break;
    case 4:
        cellList->at(position)->SetType(CellType::CELLTYPE_4);
        break;
    case 5:
        cellList->at(position)->SetType(CellType::CELLTYPE_5);
        break;
    case 6:
        cellList->at(position)->SetType(CellType::CELLTYPE_6);
        break;
    case 7:
        cellList->at(position)->SetType(CellType::CELLTYPE_7);
        break;
    case 8:
        cellList->at(position)->SetType(CellType::CELLTYPE_8);
        break;
    }

    
}
