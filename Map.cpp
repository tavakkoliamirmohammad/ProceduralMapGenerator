#include "Map.h"

Map::Map(int row, int column) : column_(column), row_(row) {
    for (int i = 0; i < row_; ++i) {
        tileMap_.emplace_back(column_);
    }
}

vector<vector<HexagonTile *>> Map::getTileMap() {
    return tileMap_;
}
