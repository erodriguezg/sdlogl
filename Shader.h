//
// Created by lalo on 15-04-18.
//

#ifndef SDLOGL_SHADER_H
#define SDLOGL_SHADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>
#include "Transform.h"

class Shader {

public:
    Shader(const std::string &fileName);
    virtual ~Shader();

    void bind();
    void update(const Transform &transform);

private:
    static const unsigned int NUM_SHADERS = 2;

    enum {
        TRANSFORM_U,
        NUM_UNIFORMS
    };

    GLuint program;
    GLuint shaders[NUM_SHADERS];
    GLuint uniforms[NUM_UNIFORMS];
};


#endif //SDLOGL_SHADER_H
