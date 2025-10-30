#include "power.h"

Power::Power(View* v, FieldStrings field_strings) {
    this->_view = v;
    power_option = {LINE_ONE, LINE_TWO};
    current_index = 0;
    this->_field_strings = field_strings;
    this->_field_strings.field_one_string = "Power Submenu Line 1";
    this->_field_strings.field_two_string = "Power Submenu Line 2";
    this->_field_strings.field_three_string = "";
    this->_field_strings.highlighted[0] = true;
    this->_field_strings.highlighted[1] = false;
    this->_field_strings.highlighted[2] = false;
    
    power_menu_actions = {
        {LINE_ONE, [this]() {
            _view->changeState(_parent);
            //std::cout << "Returned to Dashboard\n";
        }},
        {LINE_TWO, [this]() {
            //std::cout << "Selected Power Line Two, do nothing\n";
        }}
    };
}

void Power::button_up_pressed() {
    current_index = (current_index - 1 + power_option.size()) % power_option.size();
    // std::cout << "Scrolled to option " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
}

void Power::button_down_pressed() {
    current_index = (current_index + 1) % power_option.size();
    // std::cout << "Scrolled to option " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
}

void Power::button_select_pressed() {
    PowerOptions selected = power_option[current_index];
    if (power_menu_actions.count(selected)) {
        power_menu_actions[selected](); // execute the action
    }
}
