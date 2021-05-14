#ifndef MAP_GENERATION_OPENGLRENDERER_H
#define MAP_GENERATION_OPENGLRENDERER_H

#include "Renderer.h"

class OpenGLRenderer : public Renderer {
public:
    OpenGLRenderer();

    void init(int argc, char **argv) override;

    void render(void (*callback)()) override;

    void reshape() override;

    void setupWindow(int width, int height, const string &title) override;

    void loop() override;

    void specialKeyboardFunction(void (*callback)(int, int, int)) override;

    void reConfigureCamera() override;

    void timerFunction(unsigned int time, void (*callback)(int), int value) override;

private:
    static void reshapeCallback(int width, int height);

    static Camera *camera_;
};

#endif //MAP_GENERATION_OPENGLRENDERER_H
