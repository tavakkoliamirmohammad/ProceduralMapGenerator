#ifndef MAP_GENERATION_RENDERER_H
#define MAP_GENERATION_RENDERER_H

#include <string>
#include "Camera.h"


using namespace std;

class Renderer {
public:
    static Camera *getCamera();

    virtual void reConfigureCamera() = 0;

    virtual int getWindowWidth() = 0;

    virtual int getWindowHeight() = 0;

protected:
    virtual void init(int argc, char **argv) = 0;

    virtual void render(void (*callback)(void)) = 0;

    virtual void loop() = 0;

    virtual void reshape() = 0;

    virtual void setupWindow(int width, int height, const string &title) = 0;

    virtual void specialKeyboardFunction(void (*callback)(int, int, int)) = 0;

    virtual void timerFunction(unsigned int time, void (*callback)(int), int value) = 0;

    virtual void selectCallback(void (*callback)(int, int, int, int)) = 0;


    static Camera *camera_;

};

#endif //MAP_GENERATION_RENDERER_H
