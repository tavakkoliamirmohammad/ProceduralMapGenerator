#include "UnSelectedHexagonTileState.h"
#include "GL/glut.h"

using namespace std;

void UnSelectedHexagonTileState::renderPostAction() {
    glScalef(1, 1, 1);
}

UnSelectedHexagonTileState::~UnSelectedHexagonTileState() {
    glScalef(1, 1, 1);
}
