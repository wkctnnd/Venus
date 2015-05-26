#ifndef STATICMESH_H
#define STATICMESH_H
#include "Container/string.h"
#include "Container/vector.h"


namespace Venus
{
    namespace Resource
    {
    class StaticMesh
    {
    public:
        void saveToFile(Utility::VString file);
        void loadFromFile(Utility::VString file);

    private:
        Utility::VVector<float> mPosition; 
        Utility::VVector<int> mIndex;
        Utility::VVector<float> mTexcoord;
        Utility::VVector<float> mNormal;
        Utility::VVector<float> mTangent;
    };
    }
}
#endif