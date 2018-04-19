//
// Created by lalo on 15-04-18.
//

#include "Shader.h"

static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);

static std::string loadShader(const std::string &fileName);

static GLuint createShader(const std::string &text, GLenum shaderType);

Shader::Shader(const std::string &fileName) {
    this->program = glCreateProgram();
    this->shaders[0] = createShader(loadShader(fileName + ".vs.glsl"), GL_VERTEX_SHADER);
    this->shaders[1] = createShader(loadShader(fileName + ".fs.glsl"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glAttachShader(this->program, this->shaders[i]);
    }

    glBindAttribLocation(this->program, 0, "position");
    glBindAttribLocation(this->program, 1, "texCoord");

    glLinkProgram(this->program);
    checkShaderError(this->program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

    glValidateProgram(this->program);
    checkShaderError(this->program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

    this->uniforms[TRANSFORM_U] = glGetUniformLocation(this->program, "transform");
}

Shader::~Shader() {
    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glDetachShader(this->program, this->shaders[i]);
        glDeleteShader(this->shaders[i]);
    }
    glDeleteProgram(this->program);
}

void Shader::bind() {
    glUseProgram(this->program);
}

void Shader::update(const Transform &transform, const Camera &camera) {
    glm::mat4  model = camera.getViewProjection() * transform.getModel();
    glUniformMatrix4fv(this->uniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
}

static GLuint createShader(const std::string &text, GLenum shaderType) {
    GLuint shader = glCreateShader(shaderType);
    if(shader == 0) {
        std::cerr << "Error: Shader creation failed!" << std::endl;
    }

    const GLchar *shaderSourceStrings[1];
    GLint shaderSourceStringLength[1];

    shaderSourceStrings[0] = text.c_str();
    shaderSourceStringLength[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLength);
    glCompileShader(shader);

    checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed: ");

    return shader;
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
