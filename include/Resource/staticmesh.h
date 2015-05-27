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
        f32* mPosition; 
        f32* mTexcoord;
        f32* mColor;


        Utility::VVector<f32*> mTangent;
        Utility::VVector<f32> mNormal;
        Utility::VVector<f32> mBNormal;
        
    };
}
#endif