#ifndef MAP_GENERATION_HEXAGONTEXTURE_H
#define MAP_GENERATION_HEXAGONTEXTURE_H

#include "TextureLoader.h"

class HexagonTexture {
public:
    HexagonTexture(const string& path);

    GLuint getTextureId();

private:
    GLuint textureId_;
};

#endif //MAP_GENERATION_HEXAGONTEXTURE_H
