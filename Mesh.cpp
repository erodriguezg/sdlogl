//
// Created by lalo on 16-04-18.
//

#include "Mesh.h"
#include <vector>

Mesh::Mesh(Vertex *vertices, unsigned int numVertices, unsigned int *indices, unsigned int numIndices) {
    IndexedModel model;
    for(unsigned int i = 0; i < numVertices; i++) {
        model.positions.push_back(vertices[i].getPos());
        model.texCoords.push_back(vertices[i].getTexCoord());
        model.normals.push_back(vertices[i].getNormal());
    }
    for(unsigned int i = 0; i < numIndices; i++){
        model.indices.push_back(indices[i]);
    }
    initMesh(model);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, & this->vertexArrayObject);
}

void Mesh::draw() {

    glBindVertexArray(this->vertexArrayObject);

    //glDrawArrays(GL_TRIANGLES, 0, this->drawCount);
    glDrawElements(GL_TRIANGLES, this->drawCount, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

}

Mesh::Mesh(const std::string &fileName) {
    IndexedModel model = OBJModel(fileName).ToIndexedModel();
    initMesh(model);
}

void Mesh::initMesh(const IndexedModel &model) {

    drawCount = model.indices.size();

    glGenVertexArrays(1, & this->vertexArrayObject);
    glBindVertexArray(this->vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, this->vertexArrayBuffers);

    //POSITIONS
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.positions.size() * sizeof(model.positions[0]), &model.positions[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //TEXTURE COORDS
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.texCoords.size() * sizeof(model.texCoords[0]), &model.texCoords[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

    //NORMALS
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexArrayBuffers[NORMAL_VB]);
    glBufferData(GL_ARRAY_BUFFER, model.normals.size() * sizeof(model.normals[0]), &model.normals[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //INDEX MODEL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->vertexArrayBuffers[INDEX_VB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, model.indices.size() * sizeof(model.indices[0]), &model.indices[0], GL_STATIC_DRAW);

    glBindVertexArray(0);

}

//Vertex Class

Vertex::Vertex(const glm::vec3 &pos, const glm::vec2 &texCoord, const glm::vec3 &normal) {
    this->pos = pos;
    this->texCoord = texCoord;
    this->normal = normal;
}

const glm::vec3 &Vertex::getPos() {
    return this->pos;
}

const glm::vec2 &Vertex::getTexCoord() {
    return this->texCoord;
}

const glm::vec3 &Vertex::getNormal() {
    return this->normal;
}

