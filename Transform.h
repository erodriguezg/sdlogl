//
// Created by lalo on 18-04-18.
//

#ifndef SDLOGL_TRANSFORM_H
#define SDLOGL_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform {

public:
    Transform(const glm::vec3 &position = glm::vec3(),
              const glm::vec3 &rotation = glm::vec3(),
              const glm::vec3 &scale = glm::vec3(1.0f, 1.0f, 1.0f)) :
            position(position),
            rotation(rotation),
            scale(scale) {}

    inline glm::mat4 getModel() const {
        glm::mat4 posMatrix = glm::translate(this->position);
        glm::mat4 rotXMatrix = glm::rotate(rotation.x, glm::vec3(1,0,0));
        glm::mat4 rotYMatrix = glm::rotate(rotation.y, glm::vec3(0,1,0));
        glm::mat4 rotZMatrix = glm::rotate(rotation.z, glm::vec3(0,0,1));
        glm::mat4 scaleMatrix = glm::scale(this->scale);

        glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        return posMatrix * rotMatrix * scaleMatrix;
    }

    inline glm::vec3 &getPosition() {
        return position;
    }

    void setPosition(const glm::vec3 &position) {
        this->position = position;
    }

    inline glm::vec3 &getRotation() {
        return rotation;
    }

    void setRotation(const glm::vec3 &rotation) {
        this->rotation = rotation;
    }

    inline glm::vec3 &getScale() {
        return scale;
    }

    void setScale(const glm::vec3 &scale) {
        this->scale = scale;
    }

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};


#endif //SDLOGL_TRANSFORM_H
