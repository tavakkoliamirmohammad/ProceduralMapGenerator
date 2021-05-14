#ifndef MAP_GENERATION_MAP_H
#define MAP_GENERATION_MAP_H

#include <vector>
#include "HexagonTile.h"

using namespace std;

class Map {
public:
    Map(int n, vector<HexagonTexture *> loadedTexture);

    vector<vector<HexagonTile *>> getTileMap();

private:
    vector<vector<HexagonTile *>> tileMap_;
    int n_;

};

#endif //MAP_GENERATION_MAP_H
