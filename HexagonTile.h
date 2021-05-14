#ifndef MAP_GENERATION_HEXAGONTILE_H
#define MAP_GENERATION_HEXAGONTILE_H

#include "HexagonTexture.h"

class HexagonTile {
public:
    HexagonTile(HexagonTexture *hexagonTexture, int size);

    void render() const;

private:
    HexagonTexture *hexagonTexture_;
    int size_;
};

#endif //MAP_GENERATION_HEXAGONTILE_H
