#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera{
    public:
        Camera(const glm::vec3& initPos, float fov, float aspect, float zNear, float zFar);
        inline glm::mat4 getViewProjection() const{
            return perspective * glm::lookAt(pos, pos + viewForward, viewUp);
        }
        void moveZ(const float da);
        void moveX(const float da);
        void moveY(const float da);
        void move();
        void rotate(float dx, float dy, float dz);
        void finishRotation(float dx, float dy, float dz);
        void fitViewToWindow(float aspect);
    protected:
    private:
        glm::mat4 perspective;
        glm::vec3 pos;
        glm::vec3 rot;
        glm::vec3 viewForward;
        glm::vec3 viewUp;
        glm::vec3 moveSide;
        glm::vec3 moveForward;
        glm::vec3 moveUp;
        glm::vec3 velocity;
};

#endif
