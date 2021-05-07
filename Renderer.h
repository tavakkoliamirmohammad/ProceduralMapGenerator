#ifndef MAP_GENERATION_RENDERER_H
#define MAP_GENERATION_RENDERER_H

#include <string>

using namespace std;

class Renderer {
protected:
    virtual void init(int argc, char **argv) = 0;

    virtual void render(void (*callback)(void)) = 0;

    virtual void loop() = 0;
//    virtual void keyboardFunction(void (*callback)(unsigned char, int, int)) = 0;

    virtual void setupWindow(int width, int height, const string &title) = 0;
};

#endif //MAP_GENERATION_RENDERER_H
