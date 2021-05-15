#include "InputHandler.h"
#include "GL/glut.h"
#include "MoveCameraCommand.h"

InputHandler::InputHandler(Renderer *renderer, int size) : renderer_(renderer), size_(size) {

}

Command *InputHandler::handleInput(int key, int x, int y) const {
    switch (key) {
        case GLUT_KEY_UP:
            return new MoveCameraCommand(Renderer::getCamera(), 0, -1, size_);
        case GLUT_KEY_DOWN:
            return new MoveCameraCommand(Renderer::getCamera(), 0, 1, size_);

        case GLUT_KEY_LEFT:
            return new MoveCameraCommand(Renderer::getCamera(), -1, 0, size_);

        case GLUT_KEY_RIGHT:
            return new MoveCameraCommand(Renderer::getCamera(), 1, 0, size_);

    }
    return nullptr;
}

