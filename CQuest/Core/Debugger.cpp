#include "stdafx.h"
#include "Debugger.h"


Debugger::Debugger()
{
}


Debugger::~Debugger()
{
	Print("Debugger() Destructor.");
}

// Prints a message to the console if debug mode is active.
void Debugger::Print(std::string message) const
{
	if (DEBUG_MODE)
	{
		std::cout << "::::DEBUGGER:::::\t" << message << std::endl;
	}
}