#include "wifi.h"

Wifi::Wifi(View* v, FieldStrings field_strings) {
    this->_view = v;
    wifi_option = {LINE_ONE, LINE_TWO};
    current_index = 0;
    this->_field_strings = field_strings;
    this->_field_strings.field_one_string = "Wifi Submenu line one";
    this->_field_strings.field_two_string = "Wifi Submenu line two";
    this->_field_strings.field_three_string = "";
    this->_field_strings.highlighted[0] = true;
    this->_field_strings.highlighted[1] = false;
    this->_field_strings.highlighted[2] = false;
    wifi_menu_actions = {
        {LINE_ONE, [this]() {
            _view->changeState(_parent);
            std::cout << "Returned to Dashboard\n";
        }},
        {LINE_TWO, [this]() {
            std::cout << "Selected Wifi Line Two, do nothing\n";
        }}
    };
}

void Wifi::button_up_pressed() {
    current_index = (current_index - 1 + wifi_option.size()) % wifi_option.size();
    //std::cout << "Scrolled to option " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;

}

void Wifi::button_down_pressed() {
    current_index = (current_index + 1) % wifi_option.size();
    // std::cout << "Scrolled to option " << current_index << "\n";
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
}

void Wifi::button_select_pressed() {
    WifiOptions selected = wifi_option[current_index];
    if (wifi_menu_actions.count(selected)) {
        wifi_menu_actions[selected](); // execute the action
    }
    //
    //wifi_option[index].select()
}

