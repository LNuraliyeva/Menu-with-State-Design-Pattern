#ifndef STATE_H
#define STATE_H

#include <unordered_map>
#include <functional>

class View; // forward deklaration
class Dashboard;
class Wifi;
class Power;
class ID;

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
        
        std::unordered_map<int, std::function<void(State*)>> setChild;
        virtual void button_up_pressed() = 0;       // the funktion is made ecual 0 
        virtual void button_down_pressed() = 0;
        virtual void button_select_pressed() = 0;
};

#endif // STATE_H