#pragma once

#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();

				double					GetDeltaTime()													{ return mDeltaTime; }
				double					GetFrequency()										const;
	const		LARGE_INTEGER&			GetLastTime()										const		{ return mLastTime; }
	const		LARGE_INTEGER&			GetStartTime()										const		{ return mStartTime; }
				LARGE_INTEGER&			GetTimeStamp()													{ return mTimeStamp; }
				double					GetTotalGameTime()												{ return mTotalGameTime; }
				void					PrintFastGap();
				void					PrintModerateGap();
				void					PrintSlowGap();
				void					Reset();
				void					SetDeltaTime(double deltaTime)									{ mDeltaTime = deltaTime; }
				void					SetTotalGameTime(double totalGameTime)							{ mTotalGameTime = totalGameTime; }
				void					TakeTimeStamp(LARGE_INTEGER& timeStamp)				const;
				void					UpdateGameTime();
				void					Wait(double lengthOfWait);

private:
	double				mDeltaTime;
	double				mFrequency;
	LARGE_INTEGER		mLastTime;
	LARGE_INTEGER		mStartTime;
	LARGE_INTEGER		mTimeStamp;
	double				mTotalGameTime;
};

