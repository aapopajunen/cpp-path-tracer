#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

#include "transform.hpp"
#include "camera.hpp"

class Shader{
    public:
        Shader(const std::string& fileName);
        void bind();
        void update(const Transform& transform, const Camera& camera);
        virtual ~Shader();
    protected:
    private:
        static const unsigned int NUM_SHADERS = 2;
        Shader(const Shader& other){}
        void operator=(const Shader& other){}
        enum{
            TRANSFORM_U,
            NUM_UNIFORMS
        };
        GLuint mProgram;
        GLuint mShaders[NUM_SHADERS];
        GLuint mUniforms[NUM_UNIFORMS];
};

#endif
