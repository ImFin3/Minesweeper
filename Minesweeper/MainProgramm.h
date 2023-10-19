#ifndef C_MAIN_PROGRAMM_H

#define C_MAIN_PROGRAMM_H

#include "ProgrammSequence.h"
#include "Board.h"
#include <string>
#include <iostream>
#include <sstream>

class CMainProgramm : IProgrammSequence
{
private:
	CBoard* board = new CBoard();


	#pragma region Methods

public:
	// Geerbt über IProgrammSequence
	void Initialize(void) override;
	void Run(void) override;
	void Finalize(void) override;

private:
	CBoard Introduction(void);
	void Pause(void);
	CBoard GetBoardValues(void);
	int TryGetWidth(void);
	int TryGetHeight(void);
	int TryGetBombAmount(int numberOfFields);
	void TryGetInput(void);


	#pragma endregion Methods


};

#endif

