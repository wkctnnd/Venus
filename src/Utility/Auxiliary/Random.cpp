#include "Auxiliary/random.h"
#include <random>
#include <functional>
#include "Auxiliary/Time.h"
namespace Venus
{
	namespace Utility
	{
		BaseRandom::BaseRandom()
		{
			Clock clock;
			m_iSeed = clock.getTickTime();
		}

		template<class type>
		type BaseRandom::getRandom(type min, type max)
		{
			std::default_random_engine randomgen(m_iSeed);
			std::uniform_int_distribution<type> dis(min, max);
			auto dice = std::bind(dis, randomgen);
			return  dice();
		}
	}
}