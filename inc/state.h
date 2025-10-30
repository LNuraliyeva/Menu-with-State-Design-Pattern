#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <functional>
#include <string>
#include <cstdint>
#include <iostream>
#include <any>

class View; // forward deklaration

using Setter = std::function<void(FieldStrings&, std::any)>;

struct FieldStrings{
    std::string field_one_string;
    std::string field_two_string;
    std::string field_three_string;
    uint8_t highlighted[3];
    int device_number;
    bool wifi;
    bool ism;
    bool flash1;
    bool camera2;
    uint8_t barrety1;
    uint8_t battery2;
    uint8_t battery1_time_left;
    uint8_t battery2_time_left;
    uint8_t flash_intencity;
    int flash_count;
    int flash_count_last;
    std::string HW_version;
    std::string SW_version;
    std::string checksum;
    std::string error;
    /* instead of 3 boolens use this :  std::vector<bool> highlights(options.size(), false);
highlights[current_index] = true;
 and this field_strings.field_one_highlighted = highlights[0];
field_strings.field_two_highlighted = highlights[1];
 but without the assigning the value again just add highlighted "array" into the struct. then change them in the scroll up and down funktions 
 
 comit the changes*/ 
    void show() {
        
        std::cout << "Flash status" << std::endl;
        std::cout <<  (highlighted[0] ? 
                        " <<< " + field_one_string  : field_one_string) << std::endl;
        std::cout <<  (highlighted[1] ? 
                        field_two_string + " <<< " : field_two_string) << std::endl;  
        std::cout <<  (highlighted[2] ? 
                        field_three_string + " <<< " : field_three_string) << std::endl;
        std::cout << "----------------" << std::endl;
        std::cout << "";
    }
};
// using hashmap in order to set values to the struct of the values in the screen. 
std::unordered_map<std::string, Setter> field_setters = {
        {"field_one_string", [](FieldStrings& fs, std::any value){fs.field_one_string = std::any_cast<std::string>(value);}},
        {"field_two_string", [](FieldStrings& fs, std::any value){fs.field_two_string = std::any_cast<std::string>(value);}},
        {"field_three_string", [](FieldStrings& fs, std::any value){fs.field_three_string = std::any_cast<std::string>(value);}},
        {"device_number", [](FieldStrings& fs, std::any value){fs.device_number = std::any_cast<int>(value);}},
        {"wifi", [](FieldStrings& fs, std::any value){fs.wifi = std::any_cast<bool>(value);}},
        {"ism", [](FieldStrings& fs, std::any value){fs.ism = std::any_cast<bool>(value);}},
        {"flash1", [](FieldStrings& fs, std::any value){fs.flash1 = std::any_cast<bool>(value);}},
        {"camera2", [](FieldStrings& fs, std::any value){fs.camera2 = std::any_cast<bool>(value);}},
        {"barrety1", [](FieldStrings& fs, std::any value){fs.barrety1 = std::any_cast<uint8_t>(value);}},
        {"battery2", [](FieldStrings& fs, std::any value){fs.battery2 = std::any_cast<uint8_t>(value);}},
        {"battery1_time_left", [](FieldStrings& fs, std::any value){fs.battery1_time_left = std::any_cast<uint8_t>(value);}},
        {"battery2_time_left", [](FieldStrings& fs, std::any value){fs.battery2_time_left = std::any_cast<uint8_t>(value);}},
        {"flash_intencity", [](FieldStrings& fs, std::any value){fs.flash_intencity = std::any_cast<uint8_t>(value);}},
        {"flash_count", [](FieldStrings& fs, std::any value){fs.flash_count = std::any_cast<int>(value);}},
        {"flash_count_last", [](FieldStrings& fs, std::any value){fs.flash_count_last = std::any_cast<int>(value);}},
        {"HW_version", [](FieldStrings& fs, std::any value){fs.HW_version = std::any_cast<std::string>(value);}},
        {"SW_version", [](FieldStrings& fs, std::any value){fs.SW_version = std::any_cast<std::string>(value);}},
        {"checksum", [](FieldStrings& fs, std::any value){fs.checksum = std::any_cast<std::string>(value);}},
        {"error", [](FieldStrings& fs, std::any value){fs.error = std::any_cast<std::string>(value);}}
    };

class State{
    protected: 
        View *_view;            // pointer is used
        FieldStrings _field_strings;
        State* _parent = nullptr;
        State* _child_wifi = nullptr;
        State* _child_power = nullptr;
        State* _child_id = nullptr;
    public:
        State() {
            setChild = {
                {0, [this](State* s){ _child_wifi = s; }},
                {1, [this](State* s){ _child_power = s; }},
                {2, [this](State* s){ _child_id = s; }}
            };
        }

        virtual ~State() = default;      // virtual destructor
        void changeView(View *view){
            this->_view = view; // view changed with pointer
        }

        void setParent(State* state)
        {
            _parent = state;
        }
        FieldStrings getFieldStrings() {
            return _field_strings;
        }
        
        //FieldStrings submenu_field_strings;
        std::unordered_map<int, std::function<void(State*)>> setChild;
        virtual void button_up_pressed() = 0;       // the funktion is made ecual 0 
        virtual void button_down_pressed() = 0;
        virtual void button_select_pressed() = 0;
};

#endif // STATE_H