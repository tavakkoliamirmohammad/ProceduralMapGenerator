#include "Executor.h"
#include "FileSystem.h"

Executor::Executor() {
    FileSystem fileSystem = FileSystem::instance();
    fileSystem.filesInDirectory("./");
    vector<HexagonTexture *> loadedTexture;
    map_ = new Map(8, loadedTexture);
}


void Executor::run() {

}

void Executor::render() const {

    map_->render();
}

