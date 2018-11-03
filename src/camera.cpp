#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include "camera.hpp"

Camera::Camera(const glm::vec3& initPos, float fov, float aspect, float zNear, float zFar){
    perspective = glm::perspective(fov, aspect, zNear, zFar);
    pos = initPos;
    viewForward = glm::vec3(0, 0, 1);
    viewUp = glm::vec3(0, 1, 0);
    moveSide = glm::vec3(1, 0, 0);
    moveForward = glm::vec3(0, 0, 1);
    moveUp = glm::vec3(0, 1, 0);
    rot = glm::vec3(0, 0, 0);
    velocity = glm::vec3(0, 0, 0);
}

void Camera::fitViewToWindow(float aspect){
    perspective = glm::perspective(70.0f, aspect, 0.01f, 1000.0f);
}

void Camera::moveX(const float da){
    velocity.x = da;
}

void Camera::moveY(const float da){
    velocity.y = da;
}

void Camera::moveZ(const float da){
    velocity.z = da;
}

void Camera::move(){
    pos += velocity.x * moveSide + velocity.y * moveUp + velocity.z * moveForward;
}

void Camera::rotate(float dx, float dy, float dz){
    glm::mat4 rotXMatrix = glm::rotate(rot.x + dx, glm::vec3(1, 0, 0));
    glm::mat4 rotYMatrix = glm::rotate(rot.y + dy, glm::vec3(0, 1, 0));
    glm::mat4 rotZMatrix = glm::rotate(rot.z + dz, glm::vec3(0, 0, 1));
    glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

    glm::vec4 newViewForward = rotMatrix * glm::vec4(0, 0, 1, 1);
    viewForward.x = newViewForward.x; viewForward.y = newViewForward.y; viewForward.z = newViewForward.z;

    glm::vec4 newViewUp = rotMatrix * glm::vec4(0, 1, 0, 1);
    viewUp.x = newViewUp.x; viewUp.y = newViewUp.y; viewUp.z = newViewUp.z;

    glm::vec4 newMoveSide = rotYMatrix * glm::vec4(1, 0, 0, 1);
    moveSide.x = newMoveSide.x; moveSide.z = newMoveSide.z;

    glm::vec4 newMoveForward = rotYMatrix * glm::vec4(0, 0, 1, 1);
    moveForward.x = newMoveForward.x; moveForward.z = newMoveForward.z;
}

void Camera::finishRotation(float dx, float dy, float dz){
    rot.x += dx;
    rot.y += dy;
    rot.z += dz;
}
