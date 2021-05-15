#include "GL/glew.h"
#include "Model.h"
#include <utility>

Model::Model(vector<Vertex> vertices, vector<GLuint> indices, vector<double> textures) : vertices_(
        std::move(vertices)),
                                                                                         indices_(std::move(indices)),
                                                                                         textures_(std::move(
                                                                                                 textures)) {

}


void Model::initializeBuffer() {
    glGenBuffers(1, &vertexVBO_);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBO_);
    glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(Vertex), &vertices_[0], GL_STATIC_DRAW);

    glGenBuffers(1, &indicesVBO_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices_.size() * sizeof(GLuint), &indices_[0], GL_STATIC_DRAW);

    glGenBuffers(1, &textureVBO_);
    glBindBuffer(GL_ARRAY_BUFFER, textureVBO_);
    glBufferData(GL_ARRAY_BUFFER, textures_.size() * sizeof(double), &textures_[0], GL_STATIC_DRAW);
    glTexCoordPointer(2, GL_DOUBLE, 0, nullptr);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Model::render() const {
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vertexVBO_);
    glVertexPointer(2, GL_DOUBLE, 0, nullptr);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesVBO_);

    glBindBuffer(GL_ARRAY_BUFFER, textureVBO_);
    glTexCoordPointer(2, GL_DOUBLE, 0, nullptr);

    glDrawElements(GL_QUADS, indices_.size(), GL_UNSIGNED_INT, nullptr);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void Model::setVertices(const vector<Vertex> &vertices) {
    vertices_ = vertices;
}

void Model::setTextures(const vector<double> &textures) {
    textures_ = textures;
}

void Model::setIndices(const vector<GLuint> &indices) {
    indices_ = indices;
}
