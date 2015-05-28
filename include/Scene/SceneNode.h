#ifndef SCENENODE_H
#define SCENENODE_H
//logical relation among objects' position.
#include "Container\vector.h"
#include "Container\map.h"
class SceneObject;
namespace Venus
{
    namespace Scene
    {
        class SceneNode
        {
        public:
            void Attach(SceneObject* object);
            void Detach(int id);
        private:
            Utility::VVector<SceneObject *> mObjectArray;
            Utility::VMap<int, int> mMapping;
        };

    }
}

#endif