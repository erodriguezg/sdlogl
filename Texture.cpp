//
// Created by lalo on 16-04-18.
//

#include "Texture.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cassert>
#include <iostream>

Texture::Texture(const std::string &fileName) {

    SDL_Surface *surface = IMG_Load(fileName.c_str());

    if(surface == NULL) {
        std::cerr << "Texture loading failed for texture: " << fileName << std::endl;
    }

    glGenTextures(1, & this->textureId);
    glBindTexture(GL_TEXTURE_2D, this->textureId);

    int surfaceMode = GL_RGB;
    if(surface->format->BytesPerPixel == 4) {
        surfaceMode = GL_RGBA;
    }

    //forma de dibujar la textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //forma de disminuir o aumentar la textura
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, surfaceMode, surface->w, surface->h, 0, surfaceMode, GL_UNSIGNED_BYTE, surface->pixels);

    SDL_FreeSurface(surface);
}

Texture::~Texture() {
    glDeleteTextures(1, & this->textureId);
}

void Texture::bind(unsigned int unit) {

    assert(unit >= 0 && unit <= 31);

    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, this->textureId);
}
