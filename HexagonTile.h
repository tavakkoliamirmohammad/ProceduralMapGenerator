#ifndef MAP_GENERATION_HEXAGONTILE_H
#define MAP_GENERATION_HEXAGONTILE_H

#include "HexagonTexture.h"
#include "Renderable.h"

class HexagonTile : public Renderable {
public:
    HexagonTile(HexagonTexture *hexagonTexture, int size);

    void render() const override;

private:
    HexagonTexture *hexagonTexture_;
    int size_;
};

#endif //MAP_GENERATION_HEXAGONTILE_H
