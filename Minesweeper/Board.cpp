#include "Board.h"

std::vector<CCell> CBoard::GetCellList(void)
{
    return this->cellList;
}

int CBoard::GetCurrentPosition(void)
{
    return this->currentPosition;
}

int CBoard::GetWidth(void)
{
    return this->width;
}

int CBoard::GetHeight(void)
{
    return this->height;
}

int CBoard::GetMineCount(void)
{
    return this->mineCount;
}

int CBoard::GetListLength(void)
{
    return this->listLength;
}

GameState CBoard::GetGameState(void)
{
    return this->gameState;
}

CBoard::CBoard(int a_iWidth, int a_iHeight, int a_iMineCount)
{
    width = a_iWidth;
    height = a_iHeight;
    mineCount = a_iMineCount;
    listLength = a_iWidth * a_iHeight;
    gameState = GameState::Ongoing;
    currentPosition = 0;

    InstantiateBoardValues();
}

CBoard::CBoard()
{

}

void CBoard::InstantiateBoardValues(void)
{
    int count = 0;
    cellList.clear();

    //fill list with values
    while (count < listLength) 
    {
        cellList.push_back(CCell(CellType::CELLTYPE_EMPTY));

        if (count == 0) 
        {
            cellList.at(count).SetIsSelected(true);
        }

        count++;
    }

    count = 0;

    //change random list elements to mines
    while (count < mineCount) 
    {
        int minePos = rand() % listLength;

        if (cellList.at(minePos).GetType() == CellType::CELLTYPE_EMPTY) 
        {
            cellList.at(minePos).SetType(CellType::CELLTYPE_MINE);

            count++;
        }
    }

    count = 0;

    //set each CellType in the list
    while (count < listLength) 
    {
        CheckAndAssignBombAmountAt(count);
        count++;
    }
}

void CBoard::CheckAndAssignBombAmountAt(int position)
{
    int bombAmount = 0;

    if (cellList.at(position).GetType() == CellType::CELLTYPE_MINE) return;


    //check for how many bombs are around
    else 
    {
        //top left
        if (position - width - 1 >= 0)
        {
            if (cellList.at(position - width - 1).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //top mid
        if (position - width >= 0)
        {
            if (cellList.at(position - width).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //top right
        if (position - width + 1 >= 0)
        {
            if (cellList.at(position - width + 1).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //left
        if (position - 1 >= 0)
        {
            if (cellList.at(position - 1).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //right
        if (position + 1 < listLength)
        {
            if (cellList.at(position + 1).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //bot left 
        if (position + width - 1 < listLength) 
        {
            if (cellList.at(position + width - 1).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //bot mid
        if (position + width < listLength)
        {
            if (cellList.at(position + width).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

        //bot right
        if (position + width + 1 < listLength)
        {
            if (cellList.at(position + width + 1).GetType() == CellType::CELLTYPE_MINE) bombAmount++;
        }

    }

    switch (bombAmount)
    {
    case 0:
        cellList.at(position).SetType(CellType::CELLTYPE_EMPTY);
        break;
    case 1:
        cellList.at(position).SetType(CellType::CELLTYPE_1);
        break;
    case 2:
        cellList.at(position).SetType(CellType::CELLTYPE_2);
        break;
    case 3:
        cellList.at(position).SetType(CellType::CELLTYPE_3);
        break;
    case 4:
        cellList.at(position).SetType(CellType::CELLTYPE_4);
        break;
    case 5:
        cellList.at(position).SetType(CellType::CELLTYPE_5);
        break;
    case 6:
        cellList.at(position).SetType(CellType::CELLTYPE_6);
        break;
    case 7:
        cellList.at(position).SetType(CellType::CELLTYPE_7);
        break;
    case 8:
        cellList.at(position).SetType(CellType::CELLTYPE_8);
        break;
    }    
}

// ■ = \x25a0       □ = \x25a1      exmpl. std::wcout << L"\x25a0 / \x25a1";
// ‼ = \x203c
// ☼ = \x263c
// ⌂ = \x2302
// blue = 9         1
// green = 2        2
// red = 4          3
// darkblue = 1     4
// brown = 6        5
// cyan = 11        6
// black = 8        7
// grey = 7         8 
// white = 15

//SetConsoleTextAttribute(h, 1); -> change colour

void CBoard::Draw(void)
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    int count = 0;
    int widthCount = 0;


    //drawing
    while (count < listLength) 
    {


        //is the cell currently selected?
        if (cellList.at(count).GetIsSelected() == true) 
        {
            std::wcout << L"\x2302 "; //⌂
        }

        //was it already revealed?
        else if (cellList.at(count).GetIsRevealed() == true) 
        {
            switch (cellList.at(count).GetType())
            {
            case CellType::CELLTYPE_EMPTY:
                std::wcout << L"\x25a1 "; //□

                break;

            case CellType::CELLTYPE_1:
                SetConsoleTextAttribute(h, 9);
                std::wcout << "1 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_2:
                SetConsoleTextAttribute(h, 2);
                std::wcout << "2 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_3:
                SetConsoleTextAttribute(h, 4);
                std::wcout << "3 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_4:
                SetConsoleTextAttribute(h, 1);
                std::wcout << "4 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_5:
                SetConsoleTextAttribute(h, 6);
                std::wcout << "5 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_6:
                SetConsoleTextAttribute(h, 11);
                std::wcout << "6 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_7:
                SetConsoleTextAttribute(h, 8);
                std::wcout << "7 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_8:
                SetConsoleTextAttribute(h, 7);
                std::wcout << "8 ";
                SetConsoleTextAttribute(h, 15);

                break;

            case CellType::CELLTYPE_MINE:

                std::wcout << L"\x263c "; //☼

                break;
            }
        }

        //did the player mark it?
        else if (cellList.at(count).GetMarkedState() == true)
        {
            std::wcout << L"\x203c "; //‼
        }
        
        //player didnt mark it, didnt reveal it and also hasnt selected it 
        else 
        {
            std::wcout << L"\x25a0 "; //■
        }

        count++;
        widthCount++;


        if (widthCount == width) 
        {
            std::wcout << L"\n";
            widthCount = 0;
        }
        
    }

}

void CBoard::GoUp(void)
{
    //the player cant go up
    if (currentPosition - width < 0) 
    {
        return;
    }

    //player can go up
    cellList.at(currentPosition).SetIsSelected(false);
    cellList.at(currentPosition - width).SetIsSelected(true);

    currentPosition -= width;

}

void CBoard::GoLeft(void)
{
    //the player cant go left
    if (currentPosition - 1 < 0) 
    {
        return;
    }

    //player can go left
    cellList.at(currentPosition).SetIsSelected(false);
    cellList.at(currentPosition - 1).SetIsSelected(true);

    currentPosition -= 1;
}

void CBoard::GoDown(void)
{
    //the player cant go down
    if (currentPosition + width > listLength)
    {
        return;
    }

    //player can go down
    cellList.at(currentPosition).SetIsSelected(false);
    cellList.at(currentPosition + width).SetIsSelected(true);

    currentPosition += width;
}

void CBoard::GoRight(void)
{
    //the player cant go right
    if (currentPosition + 1 > listLength)
    {
        return;
    }

    //player can go right
    cellList.at(currentPosition).SetIsSelected(false);
    cellList.at(currentPosition + 1).SetIsSelected(true);

    currentPosition += 1;
}

void CBoard::Reveal(int position)
{
    //reveal cell on position
    cellList.at(position).SetIsRevealed(true);

    //player revealed a bomb
    //if (cellList.at(position).GetType() == CellType::CELLTYPE_MINE) { gameState = GameState::Lost; return; }

    //player revealed an empty cell -> reveal all cells around it 
    if (cellList.at(position).GetType() == CellType::CELLTYPE_EMPTY) 
    {
        //Top Left
        if (position - width - 1 >= 0 && cellList.at(position - width - 1).GetIsRevealed() == false) { Reveal(position - width - 1); }
        //Top Mid
        if (position - width >= 0 && cellList.at(position - width).GetIsRevealed() == false) { Reveal(position - width); }
        //Top Right
        if (position - width + 1 >= 0 && cellList.at(position - width + 1).GetIsRevealed() == false) { Reveal(position - width + 1); }

        //Mid Left
        if (position - 1 >= 0 && cellList.at(position - 1).GetIsRevealed() == false) { Reveal(position - 1); }
        //Mid Right
        if (position + 1 < listLength && cellList.at(position + 1).GetIsRevealed() == false) { Reveal(position + 1); }

        //Bot Left
        if (position + width - 1 < listLength && cellList.at(position + width - 1).GetIsRevealed() == false) { Reveal(position + width - 1); }
        //Bot Mid
        if (position + width < listLength && cellList.at(position + width).GetIsRevealed() == false) { Reveal(position + width); }
        //Bot Right
        if (position + width + 1 < listLength && cellList.at(position + width + 1).GetIsRevealed() == false) { Reveal(position + width + 1); }
    }

}

void CBoard::Mark(void)
{
    //cell is marked
    if (cellList.at(currentPosition).GetMarkedState()) 
    {
        cellList.at(currentPosition).SetMarkedState(false);
    }

    //cell isn't marked
    else 
    {
        cellList.at(currentPosition).SetMarkedState(true);
    }
}


