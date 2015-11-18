#ifndef TIME_H
#define  TIME_H
#include "type.h"
#include <time.h>
namespace Venus
{
	namespace Utility
	{
		typedef tm CalenderTime;
		/*struct CalenderTime
		{
			uint32 m_uYear;
			uint32 m_uMonth;
			uint32 m_uDay;
			uint32 m_uHour;
			uint32 m_uMinute;
			uint32 m_uSecond;
		};*/

		class Clock
		{
		public:
			int64 getTickTime();
			CalenderTime getUTCTime();
			CalenderTime getLocalTime();

		};


	}
}
#endif