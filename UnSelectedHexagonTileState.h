#ifndef MAP_GENERATION_UNSELECTEDHEXAGONTILESTATE_H
#define MAP_GENERATION_UNSELECTEDHEXAGONTILESTATE_H

#include "HexagonTileState.h"

class UnSelectedHexagonTileState : public HexagonTileState {
    void renderPostAction() override;

    ~UnSelectedHexagonTileState();
};

#endif //MAP_GENERATION_UNSELECTEDHEXAGONTILESTATE_H
