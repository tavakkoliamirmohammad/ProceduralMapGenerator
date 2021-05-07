#include <iostream>
#include "OpenGLRenderer.h"
#include "GL/glut.h"

void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0); glVertex3f(-0.6, -0.75, 0.5);
    glColor3f(0, 1, 0); glVertex3f(0.6, -0.75, 0);
    glColor3f(0, 0, 1); glVertex3f(0, 0.75, 0);
    glEnd();

    // Flush drawing command buffer to make drawing happen as soon as possible.
    glutSwapBuffers();
}

int main(int argc, char **argv) {
    auto openGLRenderer = OpenGLRenderer();
    openGLRenderer.init(argc, argv);
    openGLRenderer.setupWindow(800, 600, "Test");
    openGLRenderer.reshape();
    openGLRenderer.render(render);
    openGLRenderer.loop();
}
