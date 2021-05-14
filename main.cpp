#include "OpenGLRenderer.h"

#include "Executor.h"

using namespace std;
Executor *executor;

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    executor->render();
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    executor = new Executor();
    auto openGLRenderer = OpenGLRenderer();
    openGLRenderer.init(argc, argv);
    openGLRenderer.setupWindow(800, 600, "Test");
    openGLRenderer.reshape();
    openGLRenderer.render(render);
    openGLRenderer.loop();
}
