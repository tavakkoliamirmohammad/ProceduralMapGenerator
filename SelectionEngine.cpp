#include "SelectionEngine.h"
#include "SelectTileDataCarrier.h"

void SelectionEngine::checkSelection(int name) {
    SelectTileDataCarrier selectTileDataCarrier{name};
    notify(&selectTileDataCarrier, Event::SelectTile);
}
