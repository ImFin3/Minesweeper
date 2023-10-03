#include "MainProgramm.h"

void CMainProgramm::Initialize(void)
{
	*board = Introduction();
}

void CMainProgramm::Run(void)
{
}

void CMainProgramm::Finalize(void)
{
}

CBoard CMainProgramm::Introduction(void)
{
	std::wcout << "Welcome to Minesweeper console Edition!\n";
	std::cin >> "";
}

