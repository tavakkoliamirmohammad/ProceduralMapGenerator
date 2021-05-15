#ifndef MAP_GENERATION_SELECTEDHEXAGONTILESTATE_H
#define MAP_GENERATION_SELECTEDHEXAGONTILESTATE_H

#include "HexagonTileState.h"

class SelectedHexagonTileState : public HexagonTileState {
    void renderPostAction() override;

    ~SelectedHexagonTileState();
};

#endif //MAP_GENERATION_SELECTEDHEXAGONTILESTATE_H
