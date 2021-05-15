#include "HexagonTile.h"
#include "SelectTileDataCarrier.h"

HexagonTile::HexagonTile(HexagonTexture *hexagonTexture, int size, int name) : hexagonTexture_(hexagonTexture),
                                                                               size_(size),
                                                                               Selectable(name) {

}

void HexagonTile::render() const {
    auto tx_w = 1.0;
    auto tx_h = 1.0;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, hexagonTexture_->getTextureId());

    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);
    glVertex2f(0, 0);

    glTexCoord2f(1.0, 0);
    glVertex2f(tx_w, 0);

    glTexCoord2f(1.0, 1.0);
    glVertex2f(tx_w, tx_h);

    glTexCoord2f(0, 1.0);
    glVertex2f(0, tx_h);

    glEnd();

//    glBindTexture(GL_TEXTURE_2D, NULL);

}

void HexagonTile::onSelect(bool isSelected) {

}

void HexagonTile::onNotify(DataCarrier *dataCarrier, Event event) {
    if (event == Event::SelectTile &&
        dataCarrier->getDataCarrierType() == DataCarrierType::SelectTileDataCarrier) {
        processSelect(dynamic_cast<SelectTileDataCarrier *>(dataCarrier)->getName());
    }
}