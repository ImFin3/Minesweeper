#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "MainProgramm.h"

int main() 
{
    
    CMainProgramm* MinesweeperGame = new CMainProgramm();

    if(MinesweeperGame != nullptr){ MinesweeperGame->Initialize(); }

    if (MinesweeperGame != nullptr) { MinesweeperGame->Run(); }

    if (MinesweeperGame != nullptr) { MinesweeperGame->Finalize(); }

    delete MinesweeperGame;
    MinesweeperGame = nullptr;

}

