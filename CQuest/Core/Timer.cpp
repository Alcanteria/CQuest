#include "stdafx.h"
#include "Timer.h"
#include "..\Menus\Menu.h"
#include <iostream>


Timer::Timer() : mStartTime(), mTimeStamp(), mLastTime(), mFrequency(), mTotalGameTime(0.0), mDeltaTime(0.0)
{
	mFrequency = GetFrequency();
}

Timer::~Timer()
{
}

// Wrapper that calls a system method to "calibrate" our timer to the machine's clock speed.
double Timer::GetFrequency() const
{
	LARGE_INTEGER frequency;

	if (QueryPerformanceFrequency(&frequency) == false)
	{
		throw std::exception("QueryPerformanceFrequency() failed.");
	}

	return (double)frequency.QuadPart;
}

// Prints out a series lines at timed intervals. This is to make output text easier to read.
void Timer::PrintFastGap()
{
	// Placeholder for total accumulated time between spaces.
	double elapsedTime = 0;

	// Make sure you reset the clock so the starting time isn't from an earlier call to Reset();
	Reset();

	// Loops 3 times, printing a line every .33 seconds. (This is the "fast" version)
	for (int i = 0; i < 3; i++)
	{
		Menu::PrintSeperator();
		while (elapsedTime < .33)
		{
			UpdateGameTime();
			elapsedTime += GetDeltaTime();
		}
		elapsedTime = 0;
	}
}

// Prints out a series lines at timed intervals. This is to make output text easier to read.
void Timer::PrintModerateGap()
{
	// Placeholder for total accumulated time between spaces.
	double elapsedTime = 0;

	// Make sure you reset the clock so the starting time isn't from an earlier call to Reset();
	Reset();

	// Loops 3 times, printing a line every .66 seconds. (This is the "moderate" version)
	for (int i = 0; i < 3; i++)
	{
		Menu::PrintSeperator();
		while (elapsedTime < .66)
		{
			UpdateGameTime();
			elapsedTime += GetDeltaTime();
		}
		elapsedTime = 0;
	}
}

// Prints out a series lines at timed intervals. This is to make output text easier to read.
void Timer::PrintSlowGap()
{
	// Placeholder for total accumulated time between spaces.
	double elapsedTime = 0;

	// Make sure you reset the clock so the starting time isn't from an earlier call to Reset();
	Reset();

	// Loops 3 times, printing a line every second. (This is the "slow" version)
	for (int i = 0; i < 3; i++)
	{
		Menu::PrintSeperator();
		while (elapsedTime < 1)
		{
			UpdateGameTime();
			elapsedTime += GetDeltaTime();
		}
		elapsedTime = 0;
	}
}

// Prepares the timer to start tracking time from when this method is called.
void Timer::Reset()
{
	TakeTimeStamp(mStartTime);
	mTimeStamp = mStartTime;
	mLastTime = mTimeStamp;
}

/*	Gets a time stamp and saves it to the passed LARGE_INTEGER.
	-----------------------------------------------------------
	Note:	This is not a traditional time stamp. It uses the system method
			for tracking time. You can't use this result to get a value in 
			milliseconds directly. This value is simply needed to calculate
			useful values like milliseconds. */
void Timer::TakeTimeStamp(LARGE_INTEGER& timeStamp) const
{
	QueryPerformanceCounter(&timeStamp);
}

/*	This calculates and stores delta time. This must be called every frame/iteration 
	of a timed event to successfully track time. */
void Timer::UpdateGameTime()
{
	TakeTimeStamp(mTimeStamp);
	SetTotalGameTime((mTimeStamp.QuadPart - mStartTime.QuadPart) / mFrequency);
	SetDeltaTime((mTimeStamp.QuadPart - mLastTime.QuadPart) / mFrequency);
	mLastTime = mTimeStamp;
}

// Does nothing for the amount of time passed. Time is measured in seconds.
void Timer::Wait(double lengthOfWait)
{
	Reset();

	double timeElapsed = 0;

	while (timeElapsed < lengthOfWait)
	{
		UpdateGameTime();
		timeElapsed += GetDeltaTime();
	}
}