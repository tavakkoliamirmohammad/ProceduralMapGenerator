#ifndef MAP_GENERATION_HEXAGONTILESTATE_H
#define MAP_GENERATION_HEXAGONTILESTATE_H

class HexagonTileState {
public:
    virtual void renderPostAction() = 0;

    ~HexagonTileState() = default;
};

#endif //MAP_GENERATION_HEXAGONTILESTATE_H
