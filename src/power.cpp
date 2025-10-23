#include "power.h"

Power::Power(View* v) {
    this->_view = v;
    power_option = {LINE_ONE, LINE_TWO};
    current_index = 0;
    power_menu_actions = {
        {LINE_ONE, [this]() {
            _view->changeState(_parent);
            std::cout << "Returned to Dashboard\n";
        }},
        {LINE_TWO, [this]() {
            std::cout << "Selected Power Line Two, do nothing\n";
        }}
    };
}

void Power::button_up_pressed() {
    current_index = (current_index - 1 + power_option.size()) % power_option.size();
    std::cout << "Scrolled to option " << current_index << "\n";
}

void Power::button_down_pressed() {
    current_index = (current_index + 1) % power_option.size();
    std::cout << "Scrolled to option " << current_index << "\n";
}

void Power::button_select_pressed() {
    PowerOptions selected = power_option[current_index];
    if (power_menu_actions.count(selected)) {
        power_menu_actions[selected](); // execute the action
    }
}
