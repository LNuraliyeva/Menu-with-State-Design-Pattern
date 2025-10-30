#ifndef VIEW_H
#define VIEW_H

#include <memory>
#include <iostream>
#include "state.h"


class View {
private:
    State* _state;

public:
    View(State* state);
    ~View();

    void changeState(State* state);
    void press_up();
    void press_down();
    void press_select();
    void display();
};

#endif // VIEW_H
