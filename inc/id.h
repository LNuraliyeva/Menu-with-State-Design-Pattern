#ifndef ID_H
#define ID_H

#include "state.h"
#include "context.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

class ID : public State {
private:
    // enum IDOptions {
    //     LINE_ONE = 0,
    //     LINE_TWO = 1,
    //     LINE_THREE = 2
    // };
    //std::vector<IDOptions> id_option;
    std::unordered_map<int, std::function<void()>> id_menu_actions;

public:
    ID(Context* context, FieldStrings field_strings);
    // void button_up_pressed() override;
    // void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // ID_H
