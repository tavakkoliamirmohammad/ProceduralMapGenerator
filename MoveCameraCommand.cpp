#include "MoveCameraCommand.h"

MoveCameraCommand::MoveCameraCommand(Camera *camera, int x, int y, int size) : camera_(camera), newX_(x),
                                                                               newY_(y), oldY_(0),
                                                                               oldX_(0), size_(size) {
}

void MoveCameraCommand::execute() {
    oldX_ = camera_->getX();
    oldY_ = camera_->getY();
    camera_->moveByOffset(newX_, newY_, size_);
}

void MoveCameraCommand::undo() {
    camera_->moveByOffset(oldX_, oldY_, size_);
}
