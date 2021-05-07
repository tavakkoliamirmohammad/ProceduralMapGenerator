#ifndef MAP_GENERATION_MAPGENERATOR_H
#define MAP_GENERATION_MAPGENERATOR_H

#include <vector>

using namespace std;

class MapGenerator {
public:
    MapGenerator(int size);

    void generate();

    double **getMap();

    ~MapGenerator();

private:
    double **map_;
    int size_;
};

#endif //MAP_GENERATION_MAPGENERATOR_H
