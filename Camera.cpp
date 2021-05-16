#include "Camera.h"
#include "GL/glut.h"
#include <iostream>

using namespace std;

Camera::Camera() = default;


int Camera::getX() const {
    return x_;
}

int Camera::getY() const {
    return y_;
}

void Camera::moveByOffset(int x, int y, int size) {
    if (x_ + x < 0 || x_ + x + 16 > size) return;
    if (y_ + y < 0 || y + y_ + 16 > size) return;
    x_ += x;
    y_ += y;
}

void Camera::configure(int w, int h) const {
    gluOrtho2D(x_, x_ + 16, y_ + 16, y_);
    glViewport(0, 0, w, h);
}
