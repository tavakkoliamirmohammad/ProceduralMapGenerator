#ifndef MAP_GENERATION_CAMERA_H
#define MAP_GENERATION_CAMERA_H

class Camera {
public:
    Camera();

    void moveByOffset(int x, int y, int row, int height);

    int getX() const;

    int getY() const;

    void configure(int w, int h) const;

private:
    int x_ = 0, y_ = 0;
};

#endif //MAP_GENERATION_CAMERA_H
