#ifndef MAP_GENERATION_FILESYSTEM_H
#define MAP_GENERATION_FILESYSTEM_H

#include <vector>
#include <string>
#include <filesystem>
using namespace std;

class FileSystem {
public:
    static FileSystem &instance();

    vector<string> filesInDirectory(const string& path);

private:

};

#endif //MAP_GENERATION_FILESYSTEM_H
