#include "Executor.h"
#include "FileSystem.h"

Executor::Executor(Renderer *renderer) : renderer_(renderer) {
    inputHandler_ = new InputHandler(renderer_);
    FileSystem fileSystem = FileSystem::instance();
    vector<string> files = fileSystem.filesInDirectory("/home/amir/projects/gameDesign/map_generation/Tiles/Terrain");
    vector<string> texturePaths = fileSystem.filesInDirectory(files[1]);
    vector<HexagonTexture *> loadedTexture;
    loadedTexture.reserve(texturePaths.size());
    for (const auto &txPath: texturePaths) {
        loadedTexture.push_back(new HexagonTexture(txPath));
    }
    map_ = new Map(5, loadedTexture);
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
