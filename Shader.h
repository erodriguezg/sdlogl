//
// Created by lalo on 15-04-18.
//

#ifndef SDLOGL_SHADER_H
#define SDLOGL_SHADER_H

#include <string>
#include <fstream>
#include <iostream>
#include <GL/glew.h>

class Shader {

public:
    Shader(const std::string &fileName);
    virtual ~Shader();

    void bind();

private:
    static const unsigned int NUM_SHADERS = 2;
    GLuint program;
    GLuint shaders[NUM_SHADERS];
};


#endif //SDLOGL_SHADER_H
