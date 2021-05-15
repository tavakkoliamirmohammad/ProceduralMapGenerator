#include "InputHandler.h"
#include "GL/glut.h"
#include "MoveCameraCommand.h"

InputHandler::InputHandler(Renderer *renderer, int row, int height) : renderer_(renderer), row_(row), height_(height) {

}

Command *InputHandler::handleInput(int key, int x, int y) const {
    switch (key) {
        case GLUT_KEY_UP:
            return new MoveCameraCommand(Renderer::getCamera(), 0, -1, row_, height_);
        case GLUT_KEY_DOWN:
            return new MoveCameraCommand(Renderer::getCamera(), 0, 1, row_, height_);

        case GLUT_KEY_LEFT:
            return new MoveCameraCommand(Renderer::getCamera(), -1, 0, row_, height_);

        case GLUT_KEY_RIGHT:
            return new MoveCameraCommand(Renderer::getCamera(), 1, 0, row_, height_);

    }
    return nullptr;
}

