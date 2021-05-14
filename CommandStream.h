
#ifndef MAP_GENERATION_COMMANDSTREAM_H
#define MAP_GENERATION_COMMANDSTREAM_H

#include <queue>
#include "Command.h"

using namespace std;

class CommandStream {
public:
    void push(Command *command);

    Command *pop();

private:
    queue<Command *> commands_;
};

#endif //MAP_GENERATION_COMMANDSTREAM_H
