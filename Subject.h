#ifndef MAP_GENERATION_SUBJECT_H
#define MAP_GENERATION_SUBJECT_H

#include <vector>
#include "Observer.h"

using namespace std;


class Subject {
public:

    void addObserver(Observer *observer);

    void removeObserver(Observer *observer);

    void notify(DataCarrier *dataCarrier, Event event);

private:

    vector<Observer *> _observers;
};

#endif //MAP_GENERATION_SUBJECT_H
