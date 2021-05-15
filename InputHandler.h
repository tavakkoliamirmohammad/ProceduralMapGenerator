#ifndef MAP_GENERATION_INPUTHANDLER_H
#define MAP_GENERATION_INPUTHANDLER_H

#include "Command.h"
#include "Renderer.h"

class InputHandler {
public:
    InputHandler(Renderer *renderer, int size);

    Command *handleInput(int key, int x, int y) const;

private:
    Renderer *renderer_;
    int size_;
};

#endif //MAP_GENERATION_INPUTHANDLER_H
