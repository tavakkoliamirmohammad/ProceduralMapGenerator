#include "SelectTileDataCarrier.h"


SelectTileDataCarrier::SelectTileDataCarrier(int name) : name_(name) {

}


DataCarrierType SelectTileDataCarrier::getDataCarrierType() {
    return DataCarrierType::SelectTileDataCarrier;
}

int SelectTileDataCarrier::getName() const {
    return name_;
}
