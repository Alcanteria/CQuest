#pragma once

#include <iostream>
#include <string>

class Debugger
{
public:
	Debugger();
	~Debugger();

	const	static bool DEBUG_MODE = true;

			void Print(std::string message) const;
};

