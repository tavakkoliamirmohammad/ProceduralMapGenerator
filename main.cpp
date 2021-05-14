#include "OpenGLRenderer.h"

#include "Executor.h"

using namespace std;
Executor *executor;

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    executor->render();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    auto openGLRenderer = OpenGLRenderer();
    openGLRenderer.init(argc, argv);
    openGLRenderer.setupWindow(800, 600, "Test");
    openGLRenderer.reshape();
    executor = new Executor();
    openGLRenderer.render(render);
    openGLRenderer.loop();
}
