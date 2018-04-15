//
// Created by lalo on 15-04-18.
//

#ifndef SDLOGL_DISPLAY_H
#define SDLOGL_DISPLAY_H

#include <string>
#include <SDL2/SDL.h>

class Display {

public:
    Display(int width, int height, const std::string &title);
    void update ();
    virtual ~Display();
    bool isClosed();
protected:
private:
    SDL_Window *window;
    SDL_GLContext glContext;
    bool closed;
};


#endif //SDLOGL_DISPLAY_H
