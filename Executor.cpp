#include "Executor.h"
#include "FileSystem.h"

Executor::Executor() {
    FileSystem fileSystem = FileSystem::instance();
    vector<string> files = fileSystem.filesInDirectory("/home/amir/projects/gameDesign/map_generation/Tiles/Terrain");
    vector<string> texturePaths = fileSystem.filesInDirectory(files[1]);
    vector<HexagonTexture *> loadedTexture;
    loadedTexture.reserve(texturePaths.size());
    for (const auto& txPath: texturePaths) {
        loadedTexture.push_back(new HexagonTexture(txPath));
    }
    map_ = new Map(3, loadedTexture);
}


void Executor::run() {

}

void Executor::render() const {

    map_->render();
}

