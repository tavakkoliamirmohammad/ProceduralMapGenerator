#ifndef MAP_GENERATION_TEXTURELOADER_H
#define MAP_GENERATION_TEXTURELOADER_H

#include <string>
#include "GL/glut.h"

using namespace std;

class TextureLoader {
public:
    static GLuint load(const string &path);
};

#endif //MAP_GENERATION_TEXTURELOADER_H
