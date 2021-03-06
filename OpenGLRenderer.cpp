#include "GL/glew.h"
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
    glewInit();
    glutSetKeyRepeat(GLUT_KEY_REPEAT_ON);
    glClearColor(0, 0, 0, 0);
}

void OpenGLRenderer::loop() {
    glutMainLoop();
}

void OpenGLRenderer::render(void (*callback)()) {
    glutDisplayFunc(callback);
}

void OpenGLRenderer::reshape() {
    glutReshapeFunc(reshapeCallback);
}

void OpenGLRenderer::reshapeCallback(int width, int height) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(Renderer::camera_->getX(), Renderer::camera_->getX() + 20,
               Renderer::camera_->getY() + 20, Renderer::camera_->getY());
    glViewport(0, 0, width, height);

}

void OpenGLRenderer::specialKeyboardFunction(void (*callback)(int, int, int)) {
    glutSpecialFunc(callback);
}

void OpenGLRenderer::timerFunction(unsigned int time, void (*callback)(int), int value) {
    glutTimerFunc(time, callback, value);
}

void OpenGLRenderer::reConfigureCamera() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    auto w = glutGet(GLUT_WINDOW_WIDTH);
    auto h = glutGet(GLUT_WINDOW_HEIGHT);
    Renderer::camera_->configure(w, h);
}

int OpenGLRenderer::getWindowHeight() {
    return glutGet(GLUT_WINDOW_HEIGHT);
}

int OpenGLRenderer::getWindowWidth() {
    return glutGet(GLUT_WINDOW_WIDTH);
}

void OpenGLRenderer::selectCallback(void (*callback)(int, int, int, int)) {
    glutMouseFunc(callback);
}
