#ifndef MAP_GENERATION_EXECUTOR_H
#define MAP_GENERATION_EXECUTOR_H

#include "Map.h"

class Executor : public Renderable {
public:
    explicit Executor();

    void run();

    void render() const override;

private:

    Map *map_;
};

#endif //MAP_GENERATION_EXECUTOR_H
