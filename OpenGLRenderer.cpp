#include "OpenGLRenderer.h"
#include "GL/glut.h"

OpenGLRenderer::OpenGLRenderer() = default;

void OpenGLRenderer::init(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
}

void OpenGLRenderer::setupWindow(int width, int height, const string &title) {
    glutInitWindowSize(width, height);
    glutCreateWindow(title.c_str());
    glClearColor(0, 0, 0, 0);
}

void OpenGLRenderer::loop() {
    glutMainLoop();
}

void OpenGLRenderer::render(void (*callback)()) {
    glutDisplayFunc(callback);
}
