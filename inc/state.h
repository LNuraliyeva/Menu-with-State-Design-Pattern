#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <functional>
#include <string>
#include <cstdint>
#include <iostream>
#include <any>

class Context; // forward deklaration

struct FieldStrings{
    FieldStrings* next = nullptr;
    uint8_t highlighted[3];
    std::string device_number;    // line 1 in every menu
    std::string flash1;    // line 1 in every menu
    std::string camera2;           // line 1 in every menu

    std::string wifi;               // in dashbpoard line 1, in wifi menu line 1
    std::string barrety1;           // in dashboard line 2
    std::string battery2;           // in dashboard line 2
    std::string battery1_time_left; // in dashboard line 2
    std::string battery2_time_left; // in dashboard line 2
    std::string flash_intencity;    // in dashboard line 3
    std::string module_id;          // in dashboard line 4

    std::string ism;                // in wifi menu line 2
    
    std::string flash_count;        // in power line 1
    std::string flash_count_last;   // in power line 2

    std::string HW_version;         // in ID line 1
    std::string SW_version;         // in ID line 2
    std::string checksum;           // in ID line 3

    std::string error;              // sonderfall

    std::string field_one_string = " ";
    std::string field_two_string = " ";
    std::string field_three_string = " ";
    std::string field_four_string = " ";
    std::string field_five_string = " ";
    std::string field_six_string = " ";

    void show() {
        
        std::cout << field_one_string << std::endl;
        std::cout <<  (highlighted[0] ? 
                        field_two_string + " <<< "  : field_two_string) << std::endl;
        std::cout <<  (highlighted[1] ? 
                        field_three_string + " <<< " : field_three_string) << std::endl;  
        std::cout <<  (highlighted[2] ? 
                        field_four_string + " <<< " : field_four_string) << std::endl;
        
        std::cout << "----------------" << std::endl;
        std::cout << "";
    }
};

using Setter = std::string FieldStrings::*;

static const std::unordered_map<std::string, Setter> field_setters = {
        {"device_number", &FieldStrings::device_number},
        {"wifi", &FieldStrings::wifi},
        {"ism", &FieldStrings::ism},
        {"flash1", &FieldStrings::flash1},
        {"camera2", &FieldStrings::camera2},
        {"barrety1", &FieldStrings::barrety1},
        {"battery2", &FieldStrings::battery2},
        {"battery1_time_left", &FieldStrings::battery1_time_left},
        {"battery2_time_left", &FieldStrings::battery2_time_left},
        {"flash_intencity", &FieldStrings::flash_intencity},
        {"flash_count", &FieldStrings::flash_count},
        {"flash_count_last", &FieldStrings::flash_count_last},
        {"HW_version", &FieldStrings::HW_version},
        {"SW_version", &FieldStrings::SW_version},
        {"checksum", &FieldStrings::checksum},
        {"error", &FieldStrings::error}
    };

   inline void set_field(FieldStrings& fs, std::string_view key, std::string value){
        if(auto it = field_setters.find(std::string(key)); it != field_setters.end()){
            fs.*(it->second) = std::move(value);
        } else {
            throw std::invalid_argument("Unknown Field: " + std::string(key));
        }
    }

class State{
    protected: 
        Context *_context;                // pointer is used
        FieldStrings _field_strings;
        State* _parent = nullptr;
        State* _child_wifi = nullptr;
        State* _child_power = nullptr;
        State* _child_id = nullptr;
        int current_index = 0;
        // enum Options {
        //     LINE_ONE = 0,
        //     LINE_TWO = 1,
        //     LINE_THREE = 2,
        //     LINE_FOUR = 3,
        //     LINE_FIVE = 4,
        //     LINE_SIX = 5
        // };

        // std::vector<Options> options;
    public:
        State() {
            setChild = {
                {0, [this](State* s){ _child_wifi = s; }},
                {1, [this](State* s){ _child_power = s; }},
                {2, [this](State* s){ _child_id = s; }}
            };
        }

        virtual ~State() = default;     // virtual destructor
        void changeContext(Context *context){
            this->_context = context;         // view changed with pointer
        }

        // void scroll_down(){
        //     _field_strings.field_two_string = _field_strings.field_four_string;
        //     _field_strings.field_three_string = _field_strings.field_five_string;
        //     _field_strings.field_four_string = _field_strings.field_six_string;            
        // }
        // void scroll_up(){
        //     _field_strings.field_four_string = _field_strings.field_two_string;
        //     _field_strings.field_five_string = _field_strings.field_three_string;
        //     _field_strings.field_six_string = _field_strings.field_four_string;         
        // }

        void setParent(State* state)
        {
            _parent = state;
        }
        FieldStrings getFieldStrings() {
            return _field_strings;
        }
        
        //FieldStrings submenu_field_strings;
        std::unordered_map<int, std::function<void(State*)>> setChild;
        void button_up_pressed() {
            current_index = (current_index + 2) % 3;
            // if(current_index == -1){
            //     scroll_up();
            //     current_index = 2;
            // }
            // std::cout << "Scrolled up to line" << current_index << "\n";
            this->_field_strings.highlighted[0] = current_index == 0;
            this->_field_strings.highlighted[1] = current_index == 1;
            this->_field_strings.highlighted[2] = current_index == 2;
            
        }
        void button_down_pressed() {
            current_index = (current_index + 1) % 3;
            // if(current_index == 3){
            //     scroll_down();
            //     current_index = 0; 
            // } 
            // std::cout << "Scrolled down to line " << current_index << "\n";
            this->_field_strings.highlighted[0] = current_index == 0;
            this->_field_strings.highlighted[1] = current_index == 1;
            this->_field_strings.highlighted[2] = current_index == 2;
            
        }
        virtual void button_select_pressed() = 0;
};

#endif // STATE_H