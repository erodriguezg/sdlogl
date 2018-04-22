//
// Created by lalo on 16-04-18.
//

#ifndef SDLOGL_MESH_H
#define SDLOGL_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <string>
#include "obj_loader.h"


class Vertex {
public:
    Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord, const glm::vec3 &normal = glm::vec3(0,0,0));
    const glm::vec3 &getPos();
    const glm::vec2 &getTexCoord();
    const glm::vec3 &getNormal();
protected:
private:
    glm::vec3 pos;
    glm::vec2 texCoord;
    glm::vec3 normal;
};

class Mesh {

public:
    Mesh(Vertex *vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices);
    Mesh(const std::string &fileName);
    virtual ~Mesh();
    void draw();

private:

    void initMesh(const IndexedModel &model);

    enum {
        POSITION_VB,
        TEXCOORD_VB,
        NORMAL_VB,
        INDEX_VB,
        NUM_BUFFERS
    };

    GLuint vertexArrayObject;
    GLuint vertexArrayBuffers[NUM_BUFFERS];
    unsigned int drawCount;
};


#endif //SDLOGL_MESH_H
