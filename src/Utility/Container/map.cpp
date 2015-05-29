#include "Container\map.h"
namespace Venus
{
    namespace Utility
    {
        template<class T, class V>
        VMapIterator<T, V> VMap::insert(Pair &p)
        {
            T key = p.mSecond;

        }

         template<class T, class V>
        VMapIterator<T, V> VMap::begin()
        {
            VMapIterator<T, V> iterator(vHead);
            return iterator;
        }

        template<class T, class V>
        VMapIterator<T, V> VMap::end()
        {
             VMapIterator<T, V> iterator(vEnd);
            return iterator;
        }



    }

}