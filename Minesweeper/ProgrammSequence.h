#ifndef PROGRAMM_SEQUENCE_H

#define PROGRAMM_SEQUENCE_H

class IProgrammSequence
{
public:
	virtual void Initialize(void) = 0;
	virtual void Run(void) = 0;
	virtual void Finalize(void) = 0;
};

#endif 

