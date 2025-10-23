#include "wifi.h"

Wifi::Wifi(View* v) {
    this->_view = v;
    wifi_option = {LINE_ONE, LINE_TWO};
    current_index = 0;
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
    std::cout << "Scrolled to option " << current_index << "\n";
}

void Wifi::button_down_pressed() {
    current_index = (current_index + 1) % wifi_option.size();
    std::cout << "Scrolled to option " << current_index << "\n";
}

void Wifi::button_select_pressed() {
    WifiOptions selected = wifi_option[current_index];
    if (wifi_menu_actions.count(selected)) {
        wifi_menu_actions[selected](); // execute the action
    }
    //
    //wifi_option[index].select()
}

