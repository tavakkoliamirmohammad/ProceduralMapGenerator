#ifndef MAP_GENERATION_HEXAGONTILE_H
#define MAP_GENERATION_HEXAGONTILE_H

#include "HexagonTexture.h"

class HexagonTile {
public:
    explicit HexagonTile(HexagonTexture *hexagonTexture);

private:
    HexagonTexture *hexagonTexture_;
};

#endif //MAP_GENERATION_HEXAGONTILE_H
