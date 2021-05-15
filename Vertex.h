#ifndef MAP_GENERATION_VERTEX_H
#define MAP_GENERATION_VERTEX_H

struct Vertex {
    Vertex() = default;

    Vertex(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double x, y;
};

#endif //MAP_GENERATION_VERTEX_H
