#pragma once

#include <Windows.h>

class Timer
{
public:
	Timer();
	~Timer();

	const		LARGE_INTEGER&			StartTime()											const;
	const		LARGE_INTEGER&			CurrentTime()										const;
	const		LARGE_INTEGER&			LastTime()											const;
				double					GetTotalGameTime()												{return mTotalGameTime; }
				void					SetTotalGameTime(double totalGameTime);
				double					GetDeltaTime()													{return mDeltaTime;}
				void					SetDeltaTime(double deltaTime)									{ mDeltaTime = deltaTime; }
				void					Reset();
				double					GetFrequency()										const;
				void					GetTime(LARGE_INTEGER& time)						const;
				void					UpdateGameTime();
	const		void					PrintSlowGap();
	const		void					PrintModerateGap();
	const		void					PrintFastGap();
	const		void					Wait(double lengthOfWait);

private:
	LARGE_INTEGER		mStartTime;
	LARGE_INTEGER		mCurrentTime;
	LARGE_INTEGER		mLastTime;
	double				mFrequency;
	double				mTotalGameTime;
	double				mDeltaTime;
};

