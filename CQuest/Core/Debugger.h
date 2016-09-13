#pragma once

#include <iostream>
#include <string>

class Debugger
{
public:
	Debugger();
	~Debugger();

	const void Print(std::string message) const;

private:
	const bool DEBUG_MODE = true;
};

