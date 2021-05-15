#include "MoveCameraCommand.h"

MoveCameraCommand::MoveCameraCommand(Camera *camera, int x, int y, int row, int column) : camera_(camera), newX_(x),
                                                                                          newY_(y), oldY_(0),
                                                                                          oldX_(0), row_(row),
                                                                                          column_(column) {
}

void MoveCameraCommand::execute() {
    oldX_ = camera_->getX();
    oldY_ = camera_->getY();
    camera_->moveByOffset(newX_, newY_, row_, column_);
}

void MoveCameraCommand::undo() {
    camera_->moveByOffset(oldX_, oldY_, row_, column_);
}
