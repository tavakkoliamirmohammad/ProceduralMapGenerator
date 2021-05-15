#include "Camera.h"
#include <iostream>

using namespace std;

Camera::Camera() {
}


int Camera::getX() const {
    return x_;
}

int Camera::getY() const {
    return y_;
}

void Camera::moveByOffset(int x, int y, int row, int height) {
    if (x_ + x < 0 || x_ + x > row) return;
    if (y_ + y < 0 || y + y_ > height) return;
    cout << x_ + x << " " << row << endl;
    x_ += x;
    y_ += y;
}