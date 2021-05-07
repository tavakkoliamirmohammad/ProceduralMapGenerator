#include <iostream>
#include "OpenGLRenderer.h"
#include "GL/glut.h"
#include "MapGenerator.h"
#include <cmath>

using namespace std;

void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    int n = 8;
    int size = pow(2, n) + 1;
    auto mapGenerator = MapGenerator(size);
    mapGenerator.generate();
    auto map = mapGenerator.getMap();
    mapGenerator.
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
