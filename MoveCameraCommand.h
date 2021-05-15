#ifndef MAP_GENERATION_MOVECAMERACOMMAND_H
#define MAP_GENERATION_MOVECAMERACOMMAND_H

#include "Command.h"
#include "Camera.h"

class MoveCameraCommand : public Command {
public:

    MoveCameraCommand(Camera *camera, int x, int y, int row, int column);

    void execute() override;

    void undo() override;

private:
    Camera *camera_;
    int newX_, newY_;
    int row_, column_;
    int oldX_, oldY_;
};

#endif //MAP_GENERATION_MOVECAMERACOMMAND_H
