#ifndef PIPELINE_H
#define PIPELINE_H

//represent the gpu pipeline, various state and resources and shader program will all set into this
//partial function of device context in dx11 without deferred context or resource update...
namespace Venus
{
    namespace Graphics
    {
        class InputAssemble;
        class PipeLine
        {
        public:
            void setInputAssemble(InputAssemble *);
        };
    }
}

#endif