#include "Renderer.h"

Camera *Renderer::camera_ = new Camera();

Camera *Renderer::getCamera() {
    return camera_;
}
