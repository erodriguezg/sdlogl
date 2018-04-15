//
// Created by lalo on 15-04-18.
//

#include "Shader.h"

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);

static std::string loadShader(const std::string &fileName);

Shader::Shader(const std::string &fileName) {

}

Shader::~Shader() {

}

void Shader::bind() {

}

static std::string loadShader(const std::string &fileName) {
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if (file.is_open()) {
        while (file.good()) {
            getline(file, line);
            output.append(line + "\n");
        }
    } else {
        std::cerr << "Unable to load shader: " << fileName << std::endl;
    }
    return output;
}


static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage) {
    GLint success = 0;
    GLchar error[1024] = {0};

    if (isProgram) {
        glGetProgramiv(shader, flag, &success);
    } else {
        glGetShaderiv(shader, flag, &success);
    }

    if (success == GL_FALSE) {
        if (isProgram) {
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        } else {
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);
        }
        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
