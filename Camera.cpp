#include "Camera.h"

int Camera::getX() const {
    return x_;
}

int Camera::getY() const {
    return y_;
}

void Camera::moveByOffset(int x, int y) {
    x_ += x;
    y_ += y;
}
