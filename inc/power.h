#ifndef POWER_H
#define POWER_H

#include "state.h"
#include "context.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

class Power : public State {
private:
    // enum PowerOptions {
    //     LINE_ONE = 0,
    //     LINE_TWO = 1,
    //     LINE_THREE = 2
    // };

    // std::vector<PowerOptions> power_option;
    std::unordered_map<int, std::function<void()>> power_menu_actions;
    
public:
    Power(Context* context, FieldStrings field_strings);

    // void button_up_pressed() override;
    // void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // POWER_H
