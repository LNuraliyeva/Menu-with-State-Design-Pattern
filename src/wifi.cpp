#include "wifi.h"

Wifi::Wifi(Context* context, FieldStrings field_strings) {
    this->_context = context;
    // wifi_option = {LINE_ONE, LINE_TWO, LINE_THREE};
    current_index = 0;
    this->_field_strings = field_strings;
    this->_field_strings.field_one_string =  _field_strings.flash1 + _field_strings.device_number;
    this->_field_strings.field_two_string = "Wifi Submenu: ";
    this->_field_strings.field_three_string = "Wifi: "+ _field_strings.wifi;
    this->_field_strings.field_four_string = "ISM : " + _field_strings.ism;
    this->_field_strings.highlighted[0] = true;
    this->_field_strings.highlighted[1] = false;
    this->_field_strings.highlighted[2] = false;
    wifi_menu_actions = {
        {0, [this]() {
            _context->changeState(_parent);
            std::cout << "Returned to Dashboard\n";
        }}
    };
}

/* void Wifi::button_up_pressed() {
    current_index = current_index - 1;
    // std::cout << "Scrolled up to line" << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
    this->_field_strings.highlighted[2] = current_index == 2;
    if(current_index < 0){
        scroll_up();
        current_index = 2;
    }
}

void Wifi::button_down_pressed() {
    current_index = current_index + 1;
    // std::cout << "Scrolled down to line " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
    this->_field_strings.highlighted[2] = current_index == 2;
    if(current_index == 3){
        scroll_down();
        current_index = 0;
    } 
    
} */

void Wifi::button_select_pressed() {
    // WifiOptions selected = wifi_option[current_index];
    if (wifi_menu_actions.count(current_index)) {
        wifi_menu_actions[current_index](); // execute the action
    }
    //
    //wifi_option[index].select()
}

