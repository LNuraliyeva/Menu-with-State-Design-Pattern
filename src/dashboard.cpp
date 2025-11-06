#include "dashboard.h"
#include <iostream>

Dashboard::Dashboard(Context* context, FieldStrings field_strings) {
    this->_context = context;

    //options = {LINE_TWO, LINE_THREE, LINE_FOUR};
    current_index = 0;
    this->_field_strings = field_strings;
    this->_field_strings.field_one_string =  _field_strings.flash1 + _field_strings.device_number;
    this->_field_strings.field_two_string = "Wifi: " + _field_strings.wifi;
    this->_field_strings.field_three_string = "Battery1: " + _field_strings.barrety1 + _field_strings.battery1_time_left + 
                                              "  Battery2: " + _field_strings.battery2 + _field_strings.battery2_time_left;
    this->_field_strings.field_four_string = "Flash Intencity : " + _field_strings.flash_intencity;
    this->_field_strings.field_five_string = "Module ID: " + _field_strings.module_id;
    this->_field_strings.highlighted[0] = true;
    this->_field_strings.highlighted[1] = false;
    this->_field_strings.highlighted[2] = false;
    
    actions = {
        {0, [this]() {
            _context->changeState(_child_wifi);
            //std::cout << "Changed to Wifi submenu\n";
        }},
        {1, [this]() {
            _context->changeState(_child_power);
            //std::cout << "Changed to Power submenu\n";
        }},
        {2, [this]() {
            _context->changeState(_child_id);
            //std::cout << "Changed to ID submenu\n";
        }}
    };
}

void Dashboard::button_select_pressed() {
    if (actions.count(current_index)) {
        actions[current_index]();
    }
}

/*
void Dashboard::button_up_pressed() {
    current_index = current_index - 1 + options.size();
    // std::cout << "Scrolled up to line" << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
    this->_field_strings.highlighted[2] = current_index == 2;
    if(current_index == -1){
        scroll_up();
        current_index = 2;
    }
}

void Dashboard::button_down_pressed() {
    current_index = current_index + 1;
    // std::cout << "Scrolled down to line " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
    this->_field_strings.highlighted[2] = current_index == 2;
    if(current_index == 3){
        scroll_down();
        current_index = 0;
    } 
    
}
*/
