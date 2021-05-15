#ifndef MAP_GENERATION_EMPTYDATACARRIER_H
#define MAP_GENERATION_EMPTYDATACARRIER_H

#include "DataCarrier.h"

class EmptyDataCarrier : public DataCarrier {
    DataCarrierType getDataCarrierType() override;
};

#endif //MAP_GENERATION_EMPTYDATACARRIER_H
