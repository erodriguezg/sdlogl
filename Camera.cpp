//
// Created by lalo on 18-04-18.
//

#include "Camera.h"

Camera::Camera(const glm::vec3 &position, float fov, float aspect, float zNear, float zFar) {
    this->perspective = glm::perspective(fov, aspect, zNear, zFar);
    this->position = position;
    this->forward = glm::vec3(0, 0, 1);
    this->up = glm::vec3(0, 1, 0);
}

glm::mat4 Camera::getViewProjection() const {
    return this->perspective * glm::lookAt(this->position, this->position + this->forward, this->up);
}
