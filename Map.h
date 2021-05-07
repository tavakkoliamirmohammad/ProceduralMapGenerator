#ifndef MAP_GENERATION_MAP_H
#define MAP_GENERATION_MAP_H

#include <vector>
#include "HexagonTile.h"

using namespace std;

class Map {
public:
    Map(int row, int column);

    vector<vector<HexagonTile *>> getTileMap();

private:
    vector<vector<HexagonTile *>> tileMap_;
    int row_, column_;

};

#endif //MAP_GENERATION_MAP_H
