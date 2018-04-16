//
// Created by lalo on 16-04-18.
//

#include "Mesh.h"

Mesh::Mesh(Vertex *vertices, unsigned int numVertices) {
    drawCount = numVertices;
    glGenVertexArrays(1, & this->vertexArrayObject);
    glBindVertexArray(this->vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, this->vertexArrayBuffers);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(vertices[0]), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindVertexArray(0);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, & this->vertexArrayObject);
}

void Mesh::draw() {

    glBindVertexArray(this->vertexArrayObject);

    glDrawArrays(GL_TRIANGLES, 0, this->drawCount);

    glBindVertexArray(0);

}

//Vertex Class

Vertex::Vertex(const glm::vec3 &pos) {
    this->pos = pos;
}