//
// Created by lalo on 16-04-18.
//

#include "Mesh.h"
#include <vector>

Mesh::Mesh(Vertex *vertices, unsigned int numVertices) {
    drawCount = numVertices;
    glGenVertexArrays(1, & this->vertexArrayObject);
    glBindVertexArray(this->vertexArrayObject);

    std::vector<glm::vec3> positions;
    std::vector<glm::vec2> texCoords;

    positions.reserve(numVertices);
    texCoords.reserve(numVertices);

    for(unsigned int i = 0; i < numVertices; i++) {
        positions.push_back(vertices[i].getPos());
        texCoords.push_back(vertices[i].getTexCoord());
    }

    glGenBuffers(NUM_BUFFERS, this->vertexArrayBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

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

Vertex::Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord) {
    this->pos = pos;
    this->texCoord = texCoord;
}

const glm::vec3 &Vertex::getPos() {
    return this->pos;
}

const glm::vec2 &Vertex::getTexCoord() {
    return this->texCoord;
}
