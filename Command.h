#ifndef MAP_GENERATION_COMMAND_H
#define MAP_GENERATION_COMMAND_H

class Command {
public:
    virtual void execute() = 0;

    virtual void undo() = 0;
};

#endif //MAP_GENERATION_COMMAND_H
