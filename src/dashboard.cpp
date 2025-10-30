#include "dashboard.h"
#include <iostream>

Dashboard::Dashboard(View* v, FieldStrings field_strings) {
    this->_view = v;

    options = {"WifiSubmenu", "PowerSubmenu", "IDSubmenu"};
    current_index = 0;
    this->_field_strings = field_strings;
    this->_field_strings.field_one_string = "WifiSubmenu";
    this->_field_strings.field_three_string = "IDSubmenu";
    this->_field_strings.field_two_string = "PowerSubmenu";
    this->_field_strings.highlighted[0] = true;
    this->_field_strings.highlighted[1] = false;
    this->_field_strings.highlighted[2] = false;
    
    actions = {
        {0, [this]() {
            _view->changeState(_child_wifi);
            //std::cout << "Changed to Wifi submenu\n";
        }},
        {1, [this]() {
            _view->changeState(_child_power);
            //std::cout << "Changed to Power submenu\n";
        }},
        {2, [this]() {
            _view->changeState(_child_id);
            //std::cout << "Changed to ID submenu\n";
        }}
    };
}

void Dashboard::button_up_pressed() {
    current_index = (current_index - 1 + options.size()) % options.size();
    // std::cout << "Scrolled up to line" << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
    this->_field_strings.highlighted[2] = current_index == 2;
}

void Dashboard::button_down_pressed() {
    current_index = (current_index + 1) % options.size();
    // std::cout << "Scrolled down to line " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
    this->_field_strings.highlighted[2] = current_index == 2;
}

void Dashboard::button_select_pressed() {
    if (actions.count(current_index)) {
        actions[current_index]();
    }
}
