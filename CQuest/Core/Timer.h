#pragma once

#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();

				double					GetDeltaTime()													{ return mDeltaTime; }
				double					GetFrequency()										const;
				LARGE_INTEGER&			GetTimeStamp()													{ return mTimeStamp; }
				double					GetTotalGameTime()												{ return mTotalGameTime; }
	const		LARGE_INTEGER&			LastTime()											const;
	const		void					PrintFastGap();
	const		void					PrintModerateGap();
	const		void					PrintSlowGap();
				void					Reset();
				void					SetDeltaTime(double deltaTime)									{ mDeltaTime = deltaTime; }
				void					SetTotalGameTime(double totalGameTime);
	const		LARGE_INTEGER&			StartTime()											const;
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

