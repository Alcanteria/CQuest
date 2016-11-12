#pragma once

#include <iostream>
#include <string>

class Debugger
{
public:
	Debugger();
	~Debugger();

	// Allows different levels of message priority so some can be filtered out during testing.
	enum PRIORITY { LOW =  0, MID = 1, TOP = 2};

	const	static PRIORITY DEBUG_MODE = Debugger::PRIORITY::MID;

			void	Print(std::string message, Debugger::PRIORITY level)	const;
};

