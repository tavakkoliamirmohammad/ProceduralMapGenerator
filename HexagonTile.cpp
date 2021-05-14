#include "HexagonTile.h"

HexagonTile::HexagonTile(HexagonTexture *hexagonTexture, int size) : hexagonTexture_(hexagonTexture), size_(size) {

}

void HexagonTile::render() const {
    auto tx_w = static_cast<float >(1.0 / size_);
    auto tx_h = static_cast<float >(1.0 / size_);

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

}
