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
    
    
    //_setmode(_fileno(stdout), _O_U16TEXT);

    //HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    //
    //for (int i = 0; i < 20; i++) 
    //{
    //    SetConsoleTextAttribute(h, i);
    //    std::wcout << i << " = ";
    //    std::wcout << "Hello World \n";
    //}

    //std::wcout << L"\x25a0 / \x25a1 / \x203C";
    
}

