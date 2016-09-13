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
	const		LARGE_INTEGER&			GetStartTime()											const	{ return mStartTime; }
				LARGE_INTEGER&			GetTimeStamp()													{ return mTimeStamp; }
				double					GetTotalGameTime()												{ return mTotalGameTime; }
	const		void					PrintFastGap();
	const		void					PrintModerateGap();
	const		void					PrintSlowGap();
				void					Reset();
				void					SetDeltaTime(double deltaTime)									{ mDeltaTime = deltaTime; }
				void					SetTotalGameTime(double totalGameTime)							{ mTotalGameTime = totalGameTime; }
	const		void					TakeTimeStamp(LARGE_INTEGER& timeStamp)				const;
				void					UpdateGameTime();
	const		void					Wait(double lengthOfWait);

private:
	double				mDeltaTime;
	double				mFrequency;
	LARGE_INTEGER		mLastTime;
	LARGE_INTEGER		mStartTime;
	LARGE_INTEGER		mTimeStamp;
	double				mTotalGameTime;
};

