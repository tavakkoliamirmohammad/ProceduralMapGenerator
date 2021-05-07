#ifndef MAP_GENERATION_OPENGLRENDERER_H
#define MAP_GENERATION_OPENGLRENDERER_H

#include "Renderer.h"

class OpenGLRenderer : public Renderer {
public:
    OpenGLRenderer();

    void init(int argc, char **argv) override;

    void render(void (*callback)()) override;

    void loop() override;

    void setupWindow(int width, int height, const string &title) override;

};

#endif //MAP_GENERATION_OPENGLRENDERER_H
