#include "id.h"

ID::ID(View* view, FieldStrings field_strings) {
    this->_view = view; 
    id_option = {LINE_ONE, LINE_TWO};
    current_index = 0;
    this->_field_strings = field_strings;
    this->_field_strings.field_one_string = "Module ID Line One";
    this->_field_strings.field_two_string = "Module Id Line Two";
    this->_field_strings.field_three_string = "";
    this->_field_strings.highlighted[0] = true;
    this->_field_strings.highlighted[1] = false;
    this->_field_strings.highlighted[2] = false;
    
    id_menu_actions = {
        {LINE_ONE, [this]() {
            _view->changeState(_parent);
            std::cout << "Returned to Dashboard\n";
        }},
        {LINE_TWO, [this]() {
            std::cout << "Selected ID Line Two, do nothing\n";
        }}
    };
}

void ID::button_up_pressed() {
    current_index = (current_index - 1 + id_option.size()) % id_option.size();
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
}

void ID::button_down_pressed() {
    current_index = (current_index + 1) % id_option.size();
    this->_field_strings.highlighted[0] = current_index == 0;
    this->_field_strings.highlighted[1] = current_index == 1;
}

void ID::button_select_pressed() {
    IDOptions selected = id_option[current_index];
    if (id_menu_actions.count(selected)) {
        id_menu_actions[selected](); // execute the action
    }
}
