#include "HexagonTile.h"
#include "SelectTileDataCarrier.h"
#include "UnSelectedHexagonTileState.h"
#include "SelectedHexagonTileState.h"

HexagonTile::HexagonTile(HexagonTexture *hexagonTexture, int size, int name) : hexagonTexture_(hexagonTexture),
                                                                               size_(size), Selectable(name) {
    auto tx_w = 1.0;
    auto tx_h = 1.0;
    vector<Vertex> vertices = {Vertex(0, 0), Vertex(tx_w, 0), Vertex(tx_w, tx_h), Vertex(0, tx_h)};
    vector<GLuint> indices = {0, 1, 2, 3};
    vector<double> textures = {0, 0,
                               1.0, 0,
                               1.0, 1.0,
                               0, 1.0
    };
    setVertices(vertices);
    setTextures(textures);
    setIndices(indices);
    initializeBuffer();
    hexagonTileState_ = new UnSelectedHexagonTileState();
}

void HexagonTile::onSelect(bool isSelected) {
    delete hexagonTileState_;
    if (isSelected && !isSelected_) {
        hexagonTileState_ = new SelectedHexagonTileState();
        isSelected_ = true;
    } else {
        hexagonTileState_ = new UnSelectedHexagonTileState();
        isSelected_ = false;
    }
}

void HexagonTile::onNotify(DataCarrier *dataCarrier, Event event) {
    if (event == Event::SelectTile &&
        dataCarrier->getDataCarrierType() == DataCarrierType::SelectTileDataCarrier) {
        processSelect(dynamic_cast<SelectTileDataCarrier *>(dataCarrier)->getName());
    }
}

void HexagonTile::render() const {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, hexagonTexture_->getTextureId());
    glLoadName(selectName_);
    hexagonTileState_->renderPostAction();
    Model::render();
}
