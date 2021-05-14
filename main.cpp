#include "OpenGLRenderer.h"

#include "Executor.h"
#include "GL/gl.h"

using namespace std;
Executor *executor;

void timer(int value) {
    executor->update();
    glutTimerFunc(25, timer, value + 1);
    glutPostRedisplay();
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    executor->render();
    glutSwapBuffers();
}

void keyboardSpecialFunc(int key, int x, int y) {
    executor->handleInput(key, x, y);
}

int main(int argc, char **argv) {
    srand(time(nullptr));
    auto openGLRenderer = OpenGLRenderer();
    openGLRenderer.init(argc, argv);
    openGLRenderer.setupWindow(800, 600, "Test");
    openGLRenderer.reshape();
    executor = new Executor(&openGLRenderer);
    openGLRenderer.render(render);
    openGLRenderer.specialKeyboardFunction(keyboardSpecialFunc);
    openGLRenderer.timerFunction(25, timer, 0);
    openGLRenderer.loop();
}
