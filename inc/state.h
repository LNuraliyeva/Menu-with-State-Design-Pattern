#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <functional>
#include <string>

class View; // forward deklaration
class Dashboard;
class Wifi;
class Power;
class ID;


struct FieldStrings{
    std::string field_one_string;
    std::string field_two_string;
    std::string field_three_string;
    bool field_one_highlighted;
    bool field_two_highlighted;
    bool field_three_highlighted;

    /* instead of 3 boolens use this :  std::vector<bool> highlights(options.size(), false);
highlights[current_index] = true;
 and this field_strings.field_one_highlighted = highlights[0];
field_strings.field_two_highlighted = highlights[1];
 but without the assigning the value again just add highlighted "array" into the struct. then change them in the scroll up and down funktions */ 
};

class State{
    protected: 
        View *_view;            // pointer is used
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
        
        FieldStrings field_strings;
        FieldStrings submenu_field_strings;
        std::unordered_map<int, std::function<void(State*)>> setChild;
        virtual void button_up_pressed() = 0;       // the funktion is made ecual 0 
        virtual void button_down_pressed() = 0;
        virtual void button_select_pressed() = 0;
};

#endif // STATE_H