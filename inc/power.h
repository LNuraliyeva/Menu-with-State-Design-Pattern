#ifndef POWER_H
#define POWER_H

#include "state.h"
#include "view.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

class Power : public State {
private:
    enum PowerOptions {
        LINE_ONE = 0,
        LINE_TWO = 1
    };

    int current_index;
    std::vector<PowerOptions> power_option;
    std::unordered_map<PowerOptions, std::function<void()>> power_menu_actions;
    
public:
    Power(View* v, FieldStrings field_strings);

    void button_up_pressed() override;
    void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // POWER_H
