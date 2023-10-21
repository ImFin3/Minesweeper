#include "MainProgramm.h"



void CMainProgramm::Initialize(void)
{
	*board = Introduction();
	//Introduction();
}

void CMainProgramm::Run(void)
{
	while (board->GetGameState() == GameState::Ongoing) 
	{
		system("cls");
		board->Draw();
		TryGetInput();
		board->WinCheck();
	}

	board->EndScreen();

	
}

void CMainProgramm::Finalize(void)
{
	delete board;
	board = nullptr;
}

CBoard CMainProgramm::Introduction(void)
{
	std::string s;

	std::wcout << "Welcome to Minesweeper console Edition!\n";

	Pause();

	std::wcout << "You can move via WASD,\n";
	std::wcout << "reveal the selected Field via R,\n";
	std::wcout << "and mark the selected Field as a bomb via E!\n";

	Pause();

	return GetBoardValues();
}

void CMainProgramm::Pause(void)
{
	std::cout << "\n";
	system("pause");
	system("cls");
}

CBoard CMainProgramm::GetBoardValues(void)
{
	int width = TryGetWidth();

	int height = TryGetHeight();

	int bombAmount = TryGetBombAmount(width * height);



	return CBoard(width, height, bombAmount);
}

int CMainProgramm::TryGetWidth(void)
{
	system("cls");
	std::wcout << "How wide should the Board be?\n";
	std::wcout << "It has to be bigger than 4\n";
	std::wcout << "It has to be smaller than 66\n";

	std::string inp;

	std::cin >> inp;

	std::stringstream strm(inp);
	int value;
	strm >> value;

	try
	{
		if (value > 4 && value < 66) { return value; }
		else { throw value; }

	}
	catch (int input)
	{
		std::wcout << "The given width was either smaller than 5 or didnt contain a number!\n";
		Pause();

		return TryGetWidth();
	}
}

int CMainProgramm::TryGetHeight(void)
{
	system("cls");
	std::wcout << "How high should the Board be?\n";
	std::wcout << "It has to be bigger than 4\n";
	std::wcout << "It has to be smaller than 66\n";

	std::string inp;

	std::cin >> inp;

	std::stringstream strm(inp);
	int value;
	strm >> value;

	try
	{
		if (value > 4 && value < 66) { return value; }
		else { throw value; }

	}
	catch (int input)
	{
		std::wcout << "The given height was either smaller than 5 or didnt contain a number!\n";
		Pause();

		return TryGetHeight();
	}
}

int CMainProgramm::TryGetBombAmount(int numberOfFields)
{
	system("cls");
	std::wcout << "How many bombs should be hidden?\n";
	std::wcout << "It has to be bigger than 1, cant exceed the max number of fields(" << numberOfFields << ")!\n";

	std::string inp;

	std::cin >> inp;

	std::stringstream strm(inp);
	int value;
	strm >> value;

	try
	{
		if (value > numberOfFields) { throw value; }
		if (value > 1) { return value; }
		else { throw value; }

	}
	catch (int input)
	{
		std::wcout << "The given Bomb Amount either exceeded the limit of Fields, was smaller or equal 1 or didnt contain a number!\n";
		Pause();

		return TryGetBombAmount(numberOfFields);
	}
}

void CMainProgramm::TryGetInput(void)
{
	std::string inp;

	std::cin >> inp;

	if (inp == "w") { board->GoUp(); return; };
	if (inp == "a") { board->GoLeft(); return; };
	if (inp == "s") { board->GoDown(); return; };
	if (inp == "d") { board->GoRight(); return; };

	if (inp == "r") { board->Reveal(board->GetCurrentPosition()); return; };
	if (inp == "e") { board->Mark(); return; };
}






