#include "Auxiliary/Time.h"
#include <time.h>

namespace Venus
{
	namespace Utility
	{
		int64 Clock::getTickTime()
		{
			int64 tick = _time64(NULL);
			return tick;
		}

		CalenderTime Clock::getUTCTime()
		{
			int64 tick = _time64(NULL);
			CalenderTime t = *gmtime(&tick);
			return t;
		}

		CalenderTime Clock::getLocalTime()
		{
			int64 tick = _time64(NULL);
			CalenderTime t = *localtime(&tick);
			return t;
		}
	}
}