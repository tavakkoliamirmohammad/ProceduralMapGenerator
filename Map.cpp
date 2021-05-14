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

Map::Map(int n, vector<HexagonTexture *> loadedTexture) {
    int size = pow(2, n) + 1;
    row_ = size;
    column_ = size;
    for (int i = 0; i < row_; ++i) {
        tileMap_.emplace_back(column_);
    }
    MapGenerator mapGenerator(size);
    mapGenerator.generate();
//    TODO use map
    auto generateMap = mapGenerator.getMap();
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < column_; ++j) {
//            HexagonTexture *texture = *select_randomly(loadedTexture.begin(), loadedTexture.end());
//            tileMap_[i].push_back(new HexagonTile(texture, size));
        }
    }
}


void Map::render() const {
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < column_; ++j) {
//            tileMap_[i][j]->render();
        }
    }
}
