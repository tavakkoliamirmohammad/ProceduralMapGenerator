#include "SelectedHexagonTileState.h"
#include "GL/glut.h"

void SelectedHexagonTileState::renderPostAction() {
    glScalef(2, 2, 1);
}

SelectedHexagonTileState::~SelectedHexagonTileState() {
    glScalef(1.0 / 2, 1.0 / 2, 1);

}
