#ifndef MAP_GENERATION_SELECTTILEDATACARRIER_H
#define MAP_GENERATION_SELECTTILEDATACARRIER_H

#include "DataCarrier.h"

class SelectTileDataCarrier : public DataCarrier {
public:
    explicit SelectTileDataCarrier(int name);

    DataCarrierType getDataCarrierType() override;

    int getName() const;

private:
    int name_;
};

#endif //MAP_GENERATION_SELECTTILEDATACARRIER_H
