//
// Created by lalo on 16-04-18.
//

#ifndef SDLOGL_MESH_H
#define SDLOGL_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex {
public:
    Vertex(const glm::vec3 &pos);
protected:
private:
    glm::vec3 pos;
};

class Mesh {

public:
    Mesh(Vertex *vertices, unsigned int numVertices);
    virtual ~Mesh();
    void draw();

private:

    enum {
        POSITION_VB,
        NUM_BUFFERS
    };

    GLuint vertexArrayObject;
    GLuint vertexArrayBuffers[NUM_BUFFERS];
    unsigned int drawCount;
};


#endif //SDLOGL_MESH_H