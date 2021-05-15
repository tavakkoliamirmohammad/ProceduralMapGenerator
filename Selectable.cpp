#include "Selectable.h"

Selectable::Selectable() = default;

Selectable::Selectable(int name) {
    this->selectName_ = name;
}

Selectable *Selectable::processSelect(GLuint name) {
    if (selectName_ == name) {
        onSelect(!isSelected_);
        return this;
    } else {
        onSelect(false);
        return nullptr;
    }
}
