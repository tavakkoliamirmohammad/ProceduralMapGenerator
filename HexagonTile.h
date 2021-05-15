#ifndef MAP_GENERATION_HEXAGONTILE_H
#define MAP_GENERATION_HEXAGONTILE_H

#include "HexagonTexture.h"
#include "Renderable.h"
#include "Selectable.h"
#include "HexagonTileState.h"
#include "Model.h"

class HexagonTile : public Selectable, public Model {
public:
    HexagonTile(HexagonTexture *hexagonTexture, int size, int name);

    void onSelect(bool isSelected) override;

    void render() const override;

    void onNotify(DataCarrier *dataCarrier, Event event) override;

private:
    HexagonTexture *hexagonTexture_;
    HexagonTileState *hexagonTileState_;
    int size_;
};

#endif //MAP_GENERATION_HEXAGONTILE_H
