#ifndef MAP_GENERATION_MODEL_H
#define MAP_GENERATION_MODEL_H

#include "Vertex.h"
#include "Renderable.h"
#include <vector>
#include "GL/glut.h"

using namespace std;

class Model : public Renderable {
public:
    Model() = default;

    Model(vector<Vertex> vertices, vector<GLuint> indices, vector<double> textures);

    void render() const override;

    void initializeBuffer();

    void setVertices(const vector<Vertex> &vertices);

    void setTextures(const vector<double> &textures);

    void setIndices(const vector<GLuint> &indices);

private:
    vector<Vertex> vertices_;
    vector<double> textures_;
    vector<GLuint> indices_;
    GLuint vertexVBO_;
    GLuint indicesVBO_;
    GLuint textureVBO_;
};

#endif //MAP_GENERATION_MODEL_H
