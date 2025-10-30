#include "view.h"

View::View(State* state) {
    this->changeState(state);
}

View::~View() = default;

void View::changeState(State* state) {
    if (!state) {
        std::cerr << "Error: Tried to change to a null state.\n";
        return;
    }
    this->_state = state;
    this->_state->changeView(this);
}

void View::press_up() {
    if (_state) _state->button_up_pressed();
}

void View::press_down() {
    if (_state) _state->button_down_pressed();
}

void View::press_select() {
    if (_state) _state->button_select_pressed();
}
void View::display() {
    if (_state) {
        FieldStrings fs = _state->getFieldStrings();
        fs.show();
    }
}
