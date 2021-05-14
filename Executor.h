#ifndef MAP_GENERATION_EXECUTOR_H
#define MAP_GENERATION_EXECUTOR_H

#include "Map.h"

class Executor {
    explicit Executor(Map *map);

    void run();

private:

    Map *map_;
};

#endif //MAP_GENERATION_EXECUTOR_H
