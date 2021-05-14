#ifndef MAP_GENERATION_CAMERA_H
#define MAP_GENERATION_CAMERA_H

class Camera {
public:
    void moveByOffset(int x, int y);

    int getX() const;

    int getY() const;

private:
    int x_ = 0, y_ = 0;
};

#endif //MAP_GENERATION_CAMERA_H
