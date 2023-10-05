#include "MainProgramm.h"
#include <string>
#include <iostream>
#include <sstream>


void CMainProgramm::Initialize(void)
{
	*board = Introduction();
	//Introduction();
}

void CMainProgramm::Run(void)
{
	board->Draw();
	system("pause");
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

	PETC();

	std::wcout << "You can move via WASD,\n";
	std::wcout << "reveal the selected Field via R,\n";
	std::wcout << "and mark the selected Field as a bomb via E!\n";

	PETC();

	return GetBoardValues();
}

void CMainProgramm::PETC(void)
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

	std::string inp;

	std::cin >> inp;

	std::stringstream strm(inp);
	int value;
	strm >> value;

	try
	{
		if (value > 4) { return value; }
		else { throw value; }

	}
	catch (int input)
	{
		std::wcout << "The given width was either smaller than 5 or didnt contain a number!\n";
		PETC();

		return TryGetWidth();
	}
}

int CMainProgramm::TryGetHeight(void)
{
	system("cls");
	std::wcout << "How high should the Board be?\n";
	std::wcout << "It has to be bigger than 4\n";

	std::string inp;

	std::cin >> inp;

	std::stringstream strm(inp);
	int value;
	strm >> value;

	try
	{
		if (value > 4) { return value; }
		else { throw value; }

	}
	catch (int input)
	{
		std::wcout << "The given height was either smaller than 5 or didnt contain a number!\n";
		PETC();

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
		PETC();

		return TryGetBombAmount(numberOfFields);
	}
}





