#ifndef MAP_GENERATION_HEXAGONTILE_H
#define MAP_GENERATION_HEXAGONTILE_H

#include "HexagonTexture.h"
#include "Renderable.h"
#include "Selectable.h"
#include "HexagonTileState.h"

class HexagonTile : public Renderable, public Selectable {
public:
    HexagonTile(HexagonTexture *hexagonTexture, int size, int name);

    void render() const override;

    void onSelect(bool isSelected) override;

    void onNotify(DataCarrier *dataCarrier, Event event) override;

private:
    HexagonTexture *hexagonTexture_;
    HexagonTileState* hexagonTileState_;
    int size_;
};

#endif //MAP_GENERATION_HEXAGONTILE_H
