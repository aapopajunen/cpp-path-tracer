#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform{
    public:
        Transform(){}
        inline glm::mat4 getModel() const{
            glm::mat4 posMatrix = glm::translate(pos);
            glm::mat4 rotXMatrix = glm::rotate(rot.x, glm::vec3(1, 0, 0));
            glm::mat4 rotYMatrix = glm::rotate(rot.y, glm::vec3(0, 1, 0));
            glm::mat4 rotZMatrix = glm::rotate(rot.z, glm::vec3(0, 0, 1));
            //glm::mat4 scaleMatrix = glm::scale(mScale);
            glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;
            return posMatrix * rotMatrix; //* scaleMatrix
        }
        inline void update(const glm::vec3& p, const glm::vec3& r){
			pos = p;
			rot = r;
		}
    private:
        glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3 rot = glm::vec3(0.0f, 0.0f, 0.0f);
		//glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
};

#endif
