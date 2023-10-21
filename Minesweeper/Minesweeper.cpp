#include <iostream>
#include <Windows.h>
#include <fcntl.h>
#include <io.h>
#include "MainProgramm.h"

int main() 
{
    
    CMainProgramm* MinesweeperGame = new CMainProgramm();

    MinesweeperGame->Initialize();

    MinesweeperGame->Run();

    MinesweeperGame->Finalize();

    delete MinesweeperGame;
    MinesweeperGame = nullptr;
    
}

