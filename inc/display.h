#ifndef DISPLAY_H
#define DISPLAY_H

#include "state.h"

class Display{
    public:
        void show();
    private:
        State* current_state;
};

#endif // DISPLAY_H