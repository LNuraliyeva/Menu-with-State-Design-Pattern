#ifndef CONTEXT_H
#define CONTEXT_H

#include <memory>
#include <iostream>
#include "state.h"


class Context {
private:
    State* _state;

public:
    Context(State* state);
    ~Context();

    void changeState(State* state);
    void press_up();
    void press_down();
    void press_select();
    void display();
};

#endif // CONTEXT_H
