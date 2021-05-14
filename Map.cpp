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

Map::Map(int n, vector<HexagonTexture *> loadedTexture) : n_(n) {
    int size = pow(2, n) + 1;
    for (int i = 0; i < size; ++i) {
        tileMap_.emplace_back(size);
    }
    MapGenerator mapGenerator(size);
    mapGenerator.generate();
//    TODO use map
    auto generateMap = mapGenerator.getMap();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            HexagonTexture *texture = *select_randomly(loadedTexture.begin(), loadedTexture.end());
            tileMap_[i].push_back(new HexagonTile(texture, size));
        }
    }
}


vector<vector<HexagonTile *>> Map::getTileMap() {
    return tileMap_;
}
