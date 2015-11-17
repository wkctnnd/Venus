#include "type.h"

#include "Auxiliary/Time.h"
namespace Venus
{
	namespace Utility
	{
		enum RandomEngineType
		{

		};

		enum RandomDistributionType
		{

		};
		class BaseRandom
		{
		public:
			BaseRandom(int32 seed) :m_iSeed(seed){}
			BaseRandom();
			template<class type>
			type getRandom(type min, type max);
			void setSeed(int32 seed);
			protected:
				int32 m_iSeed;
		};
	}
}
