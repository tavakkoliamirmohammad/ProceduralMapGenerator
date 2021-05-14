#ifndef MAP_GENERATION_MAP_H
#define MAP_GENERATION_MAP_H

#include <vector>
#include "HexagonTile.h"

using namespace std;

class Map : public Renderable {
public:
    Map(int n, vector<HexagonTexture *> dirt, vector<HexagonTexture *> dirtBuilding, vector<HexagonTexture *> grass,
        vector<HexagonTexture *> grassBuilding,
        vector<HexagonTexture *> mars, vector<HexagonTexture *> sand, vector<HexagonTexture *> sandBuilding,
        vector<HexagonTexture *> stone);

    void render() const override;

private:
    vector<vector<HexagonTile *>> tileMap_;
    int row_, column_;

};

#endif //MAP_GENERATION_MAP_H
