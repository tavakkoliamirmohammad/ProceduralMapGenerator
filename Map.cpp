#include "Map.h"
#include "MapGenerator.h"
#include <cmath>
#include  <random>
#include  <iterator>

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator &g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

Map::Map(int n, vector<HexagonTexture *> dirt, vector<HexagonTexture *> dirtBuilding, vector<HexagonTexture *> grass,
         vector<HexagonTexture *> grassBuilding,
         vector<HexagonTexture *> mars, vector<HexagonTexture *> sand, vector<HexagonTexture *> sandBuilding,
         vector<HexagonTexture *> stone) {
    int size = pow(2, n) + 1;
    row_ = size;
    column_ = size;
    for (int i = 0; i < row_; ++i) {
        tileMap_.emplace_back(column_);
    }
    MapGenerator mapGenerator(size);
    mapGenerator.generate();
    auto generateMap = mapGenerator.getMap();
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < column_; ++j) {
            HexagonTexture *texture;
            if (generateMap[i][j] / 255 < 0.1) {
                texture = *select_randomly(dirt.begin(), dirt.end());

            } else if (generateMap[i][j] / 255 < 0.2) {
                texture = *select_randomly(dirtBuilding.begin(), dirtBuilding.end());

            } else if (generateMap[i][j] / 255 < 0.3) {
                texture = *select_randomly(grass.begin(), grass.end());
            } else if (generateMap[i][j] / 255 < 0.4) {
                texture = *select_randomly(grass.begin(), grass.end());
            } else if (generateMap[i][j] / 255 < 0.6) {
                texture = *select_randomly(mars.begin(), mars.end());
            } else if (generateMap[i][j] / 255 < 0.7) {
                texture = *select_randomly(sand.begin(), sand.end());
            } else if (generateMap[i][j] / 255 < 0.8) {
                texture = *select_randomly(sandBuilding.begin(), sandBuilding.end());
            } else {
                texture = *select_randomly(stone.begin(), stone.end());
            }
            tileMap_[i][j] = new HexagonTile(texture, size);
        }
    }
}


void Map::render() const {
    for (int i = 0; i < row_; ++i) {
        glPushMatrix();
        if (i % 2 == 1) {
            glTranslatef(-1.0 / 2, 0, 0);
            glTranslatef(0, -i / 4.0, 0);
        } else if (i != 0) {
            glTranslatef(0, -i / 4.0, 0);
        }
        for (int j = 0; j < column_; ++j) {
            glPushMatrix();
            glTranslatef(j, i, 0);
            tileMap_[i][j]->render();
            glPopMatrix();
        }
        glPopMatrix();
    }
}
