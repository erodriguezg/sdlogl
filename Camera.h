//
// Created by lalo on 18-04-18.
//

#ifndef SDLOGL_CAMERA_H
#define SDLOGL_CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera {

public:
    Camera(const glm::vec3 &position, float fov, float aspect, float zNear, float zFar);

    glm::mat4 getViewProjection() const;

private:
    glm::mat4 perspective;
    glm::vec3 position;
    glm::vec3 forward;
    glm::vec3 up;
};


#endif //SDLOGL_CAMERA_H
