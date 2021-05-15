#ifndef MAP_GENERATION_OBSERVER_H
#define MAP_GENERATION_OBSERVER_H

#include "DataCarrier.h"

enum class Event {
    SelectTile
};

class Observer {
public:
    virtual ~Observer() = default;

    virtual void onNotify(DataCarrier *dataCarrier, Event event) = 0;
};

#endif //MAP_GENERATION_OBSERVER_H
