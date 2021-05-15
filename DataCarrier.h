#ifndef MAP_GENERATION_DATACARRIER_H
#define MAP_GENERATION_DATACARRIER_H

enum class DataCarrierType {
    EmptyDataCarrier,
    SelectTileDataCarrier
};

struct DataCarrier {
    virtual DataCarrierType getDataCarrierType() = 0;
};

#endif //MAP_GENERATION_DATACARRIER_H
