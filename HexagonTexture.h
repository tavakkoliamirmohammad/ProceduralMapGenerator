#ifndef MAP_GENERATION_HEXAGONTEXTURE_H
#define MAP_GENERATION_HEXAGONTEXTURE_H

#include "TextureLoader.h"

class HexagonTexture {
public:
    explicit HexagonTexture(const string& path);

    GLuint getTextureId() const;

private:
    GLuint textureId_;
};

#endif //MAP_GENERATION_HEXAGONTEXTURE_H
