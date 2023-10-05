#ifndef C_MAIN_PROGRAMM_H

#define C_MAIN_PROGRAMM_H

#include "ProgrammSequence.h"
#include "Board.h"

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
	void PETC(void);
	CBoard GetBoardValues(void);
	int TryGetWidth(void);
	int TryGetHeight(void);
	int TryGetBombAmount(int numberOfFields);


	#pragma endregion Methods


};

#endif

