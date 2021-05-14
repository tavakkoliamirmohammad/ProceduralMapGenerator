#ifndef MAP_GENERATION_EXECUTOR_H
#define MAP_GENERATION_EXECUTOR_H

#include "Map.h"
#include "CommandStream.h"
#include "InputHandler.h"

class Executor : public Renderable {
public:
    explicit Executor(Renderer *renderer);

    void update();

    void render() const override;

    void handleInput(int key, int x, int y);

private:

    Map *map_;
    CommandStream commandStream_;
    InputHandler *inputHandler_;
    Renderer *renderer_;
};

#endif //MAP_GENERATION_EXECUTOR_H
