#ifndef MAP_GENERATION_SELECTABLE_H
#define MAP_GENERATION_SELECTABLE_H

#include "GL/glut.h"
#include "Observer.h"

class Selectable : public Observer {
public:
    Selectable();

    explicit Selectable(int name);


protected:
    int selectName_{};
    bool isSelected_ = false;

    virtual void onSelect(bool isSelected) = 0;

    Selectable *processSelect(GLuint name);
};

#endif //MAP_GENERATION_SELECTABLE_H
