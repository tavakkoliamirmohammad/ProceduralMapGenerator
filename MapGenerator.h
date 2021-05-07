#ifndef MAP_GENERATION_MAPGENERATOR_H
#define MAP_GENERATION_MAPGENERATOR_H

#include <vector>

using namespace std;

class MapGenerator {
public:
    explicit MapGenerator(int size);

    void generate();

    double **getMap();

    void renderMap();

    ~MapGenerator();

private:
    double **map_;
    int size_;
};

#endif //MAP_GENERATION_MAPGENERATOR_H
