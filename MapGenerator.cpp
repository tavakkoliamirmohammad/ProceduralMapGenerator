#include "MapGenerator.h"
#include "DiamondSquareMapGenerator.h"

MapGenerator::MapGenerator(int factor) {
    size_ = factor;

    map_ = new double *[size_];
    for (int i = 0; i < size_; i++) {
        map_[i] = new double[size_];
        for (int j = 0; j < size_; j++)
            map_[i][j] = 0.0;
    }
}

double **MapGenerator::getMap() {
    return map_;
}

MapGenerator::~MapGenerator() {
    for (int i = 0; i < size_; i++) {
        delete[] map_[i];
    }
    delete[] map_;
}

void MapGenerator::generate() {
    auto diamondSquareMapGenerator = DiamondSquareMapGenerator(map_, size_);
    map_ = diamondSquareMapGenerator.process();
}
