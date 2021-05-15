#ifndef MAP_GENERATION_INPUTHANDLER_H
#define MAP_GENERATION_INPUTHANDLER_H

#include "Command.h"
#include "Renderer.h"

class InputHandler {
public:
    explicit InputHandler(Renderer *renderer, int row, int height);

    Command *handleInput(int key, int x, int y) const;

private:
    Renderer *renderer_;
    int row_;
    int height_;
};

#endif //MAP_GENERATION_INPUTHANDLER_H
