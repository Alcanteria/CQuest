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

//const LARGE_INTEGER& Timer::CurrentTime() const
//{
	//return mCurrentTime;
//}

double Timer::GetFrequency() const
{
	LARGE_INTEGER frequency;

	if (QueryPerformanceFrequency(&frequency) == false)
	{
		throw std::exception("QueryPerformanceFrequency() failed.");
	}

	return (double)frequency.QuadPart;
}

//void Timer::GetTime(LARGE_INTEGER& time) const
//{
	//QueryPerformanceCounter(&time);
//}

const void Timer::TakeTimeStamp(LARGE_INTEGER& timeStamp) const
{
	QueryPerformanceCounter(&mTimeStamp);
}

const LARGE_INTEGER& Timer::LastTime() const
{
	return mLastTime;
}

// Prints out a series lines at timed intervals. This is to make output text easier to read.
const void Timer::PrintFastGap()
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
const void Timer::PrintModerateGap()
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
const void Timer::PrintSlowGap()
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

void Timer::Reset()
{
	TakeTimeStamp();
	mTimeStamp = mStartTime;
	mLastTime = mTimeStamp;
}

void Timer::SetTotalGameTime(double totalGameTime)
{
	mTotalGameTime = totalGameTime;
}

const LARGE_INTEGER& Timer::StartTime() const
{
	return mStartTime;
}

void Timer::UpdateGameTime()
{
	TakeTimeStamp();
	SetTotalGameTime((mTimeStamp.QuadPart - mStartTime.QuadPart) / mFrequency);
	SetDeltaTime((mTimeStamp.QuadPart - mLastTime.QuadPart) / mFrequency);
	mLastTime = mTimeStamp;
}

// Does nothing for the amount of time passed. Time is measured in seconds.
const void Timer::Wait(double lengthOfWait)
{
	Reset();

	double timeElapsed = 0;

	while (timeElapsed < lengthOfWait)
	{
		UpdateGameTime();
		timeElapsed += GetDeltaTime();
	}
}