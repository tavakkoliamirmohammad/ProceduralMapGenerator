#include "HexagonTexture.h"

HexagonTexture::HexagonTexture(const string &path) {
    textureId_ = TextureLoader::load(path);
}

GLuint HexagonTexture::getTextureId() const {
    return textureId_;
}
