#ifndef MAP_GENERATION_MOVECAMERACOMMAND_H
#define MAP_GENERATION_MOVECAMERACOMMAND_H

#include "Command.h"
#include "Camera.h"

class MoveCameraCommand : public Command {
    MoveCameraCommand(Camera *camera, int x, int y);

    void execute() override;

    void undo() override;

private:
    Camera *camera_;
    int newX_, newY_;
    int oldX_, oldY_;
};

#endif //MAP_GENERATION_MOVECAMERACOMMAND_H
