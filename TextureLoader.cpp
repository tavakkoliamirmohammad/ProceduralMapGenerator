#include "TextureLoader.h"

#include "SOIL.h"

GLuint TextureLoader::load(const string &path) {
    return SOIL_load_OGL_texture(path.c_str(), SOIL_LOAD_AUTO,
                                 SOIL_CREATE_NEW_ID,
                                 SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_MULTIPLY_ALPHA);
}
