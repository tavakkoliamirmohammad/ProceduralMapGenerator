#ifndef MAP_GENERATION_EXECUTOR_H
#define MAP_GENERATION_EXECUTOR_H

#include "Map.h"
#include "CommandStream.h"
#include "InputHandler.h"
#include "SelectionEngine.h"

class Executor : public Renderable {
public:
    explicit Executor(Renderer *renderer);

    void update();

    void render() const override;

    void pickItems(int button, int state, int x, int y);

    void processHits(GLint hits, GLuint *buffer);


    void handleInput(int key, int x, int y);


private:
    static vector<HexagonTexture *> getTextureFromDirectory(const vector<string> &folder);

    SelectionEngine selectionEngine_;
    Map *map_;
    CommandStream commandStream_;
    InputHandler *inputHandler_;
    Renderer *renderer_;
};

#endif //MAP_GENERATION_EXECUTOR_H
