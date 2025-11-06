#include "context.h"

Context::Context(State* state) {
    this->changeState(state);
}

Context::~Context() = default;

void Context::changeState(State* state) {
    if (!state) {
        std::cerr << "Error: Tried to change to a null state.\n";
        return;
    }
    this->_state = state;
    this->_state->changeContext(this);
}

void Context::press_up() {
    if (_state) _state->button_up_pressed();
}

void Context::press_down() {
    if (_state) _state->button_down_pressed();
}

void Context::press_select() {
    if (_state) _state->button_select_pressed();
}
void Context::display() {
    if (_state) {
        FieldStrings fs = _state->getFieldStrings();
        fs.show();
    }
}
