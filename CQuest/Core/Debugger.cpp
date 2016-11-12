#include "stdafx.h"
#include "Debugger.h"


Debugger::Debugger()
{
}


Debugger::~Debugger()
{
Print("Debugger() Destructor.", Debugger::PRIORITY::LOW);
}

// Prints a message to the console if debug mode is active.
void Debugger::Print(std::string message, Debugger::PRIORITY level) const
{
	if (level >= Debugger::DEBUG_MODE)
	{
		std::cout << "::::DEBUGGER:::::\t" << message << std::endl;
	}
}