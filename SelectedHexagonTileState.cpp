#include "SelectedHexagonTileState.h"
#include "GL/glut.h"

void SelectedHexagonTileState::renderPostAction() {
    glTranslatef(0, -0.15, 0);
}

SelectedHexagonTileState::~SelectedHexagonTileState() {
    glTranslatef(0, 0.15, 0);
}
