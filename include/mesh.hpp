#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

struct Vertex{
    glm::vec3 pos;
    glm::vec2 texCoord;
    glm::vec3 normal;
    bool operator==(Vertex other) const{
        return this->pos == other.pos && this->texCoord == other.texCoord;
    }
};

namespace std{
    template<> struct hash<Vertex>{
        size_t operator()(Vertex const& vertex) const{
            return ((hash<glm::vec3>()(vertex.pos) ^
                   (hash<glm::vec2>()(vertex.texCoord) << 1)) >> 1) ^
                   (hash<glm::vec3>()(vertex.normal) << 1);
        }
    };
}

class Mesh{
    public:
        Mesh(const char* fileName);
        void draw();
        virtual ~Mesh();
    protected:
    private:
        Mesh(const Mesh& other);
        void operator=(const Mesh& other);
        enum{
            POSITION_VB,
            TEXCOORD_VB,
            NORMAL_VB,
            INDEX_VB,
            NUM_BUFFERS
        };
        GLuint mVertexArrayObject;
        GLuint mVertexArrayBuffers[NUM_BUFFERS];
        unsigned int mDrawCount;
};

#endif
