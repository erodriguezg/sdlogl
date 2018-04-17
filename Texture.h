//
// Created by lalo on 16-04-18.
//

#ifndef SDLOGL_TEXTURE_H
#define SDLOGL_TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture {


public:
    Texture(const std::string &fileName);
    virtual ~Texture();
    void bind(unsigned int unit);

private:
    GLuint textureId;
};


#endif //SDLOGL_TEXTURE_H
