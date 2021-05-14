#include "Executor.h"
#include "FileSystem.h"

Executor::Executor(Renderer *renderer) : renderer_(renderer) {
    inputHandler_ = new InputHandler(renderer_);
    FileSystem fileSystem = FileSystem::instance();
    string basePath = "/home/amir/projects/gameDesign/map_generation/Tiles/Terrain";
    vector<HexagonTexture *> dirt = getTextureFromDirectory(fileSystem.filesInDirectory(basePath + "/Dirt"));
    vector<HexagonTexture *> grass = getTextureFromDirectory(fileSystem.filesInDirectory(basePath + "/Grass"));
    vector<HexagonTexture *> mars = getTextureFromDirectory(fileSystem.filesInDirectory(basePath + "/Mars"));
    vector<HexagonTexture *> sand = getTextureFromDirectory(fileSystem.filesInDirectory(basePath + "/Sand"));
    vector<HexagonTexture *> stone = getTextureFromDirectory(fileSystem.filesInDirectory(basePath + "/Stone"));
    map_ = new Map(8, dirt, grass, mars, sand, stone);
}


void Executor::update() {
    auto command = commandStream_.pop();
    if (command != nullptr) {
        command->execute();
    }
    renderer_->reConfigureCamera();
}

void Executor::render() const {

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

