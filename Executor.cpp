#include "Executor.h"
#include "FileSystem.h"

#define BUFFER_SIZE 512

Executor::Executor(Renderer *renderer) : renderer_(renderer) {
    FileSystem fileSystem = FileSystem::instance();
    string basePath = "/home/amir/projects/gameDesign/map_generation";
    vector<HexagonTexture *> dirt = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Tiles/Terrain/Dirt"));
    vector<HexagonTexture *> dirtBuilding = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Buildings/Dirt"));
    vector<HexagonTexture *> grass = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Tiles/Terrain/Grass"));
    vector<HexagonTexture *> grassBuilding = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Buildings/Grass"));
    vector<HexagonTexture *> mars = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Tiles/Terrain/Mars"));
    vector<HexagonTexture *> sand = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Tiles/Terrain/Sand"));
    vector<HexagonTexture *> sandsBuilding = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Buildings/Sand"));
    vector<HexagonTexture *> stone = getTextureFromDirectory(
            fileSystem.filesInDirectory(basePath + "/Tiles/Terrain/Stone"));
    selectionEngine_ = SelectionEngine();
    map_ = new Map(3, dirt, dirtBuilding, grass, grassBuilding, mars, sand, sandsBuilding, stone, &selectionEngine_);
    inputHandler_ = new InputHandler(renderer_, renderer_->getWindowWidth(), renderer_->getWindowHeight());

}


void Executor::update() {
    auto command = commandStream_.pop();
    if (command != nullptr) {
        command->execute();
    }
    renderer_->reConfigureCamera();
}

void Executor::render() const {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    map_->render();
}

void Executor::handleInput(int key, int x, int y) {
    auto command = inputHandler_->handleInput(key, x, y);
    if (command != nullptr) {
        commandStream_.push(command);
    }
}

vector<HexagonTexture *> Executor::getTextureFromDirectory(const vector<string> &folder) {
    vector<HexagonTexture *> textures;
    textures.reserve(folder.size());
    for (const auto &path:folder) {
        textures.push_back(new HexagonTexture(path));
    }
    return textures;
}

void Executor::pickItems(int button, int state, int x, int y) {
    GLuint selectBuf[BUFFER_SIZE];
    GLint hits;
    GLint viewport[4];
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    glGetIntegerv(GL_VIEWPORT, viewport);
    glSelectBuffer(BUFFER_SIZE, selectBuf);
    glRenderMode(GL_SELECT);

    glInitNames();
    glPushName(-1);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluPickMatrix((GLdouble) x, (GLdouble) (viewport[3] - y), 5.0, 5.0, viewport);

    auto w = glutGet(GLUT_WINDOW_WIDTH);
    auto h = glutGet(GLUT_WINDOW_HEIGHT);
    Renderer::getCamera()->configure(w, h);

    render();
    glLoadName(-1);
    glPopMatrix();
    glutSwapBuffers();

    hits = glRenderMode(GL_RENDER);
    processHits(hits, selectBuf);
}

void Executor::processHits(GLint hits, GLuint *buffer) {
    if (hits == 0) {
        selectionEngine_.checkSelection(-1);
    }
    unsigned int i, j;
    GLuint names, *ptr, minZ, *ptrNames;

    ptr = (GLuint *) buffer;
    minZ = 0xffffffff;
    for (i = 0; i < hits; i++) {
        names = *ptr;
        ptr++;
        if (*ptr < minZ) {
            minZ = *ptr;
            ptrNames = ptr + 2;
        }
        ptr += names + 2;
    }
    ptr = ptrNames;
    selectionEngine_.checkSelection(*ptr);
}

