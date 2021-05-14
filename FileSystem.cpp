#include "FileSystem.h"
#include <iostream>
#include <filesystem>


FileSystem &FileSystem::instance() {
    static FileSystem *fileSystem_;
    if (fileSystem_ == nullptr) fileSystem_ = new FileSystem();
    return *fileSystem_;
}

vector<string> FileSystem::filesInDirectory(const string &path) {
    vector<string> files;
    for (const auto &entry : std::filesystem::directory_iterator(path))
        files.push_back(entry.path());
    return files;
}
