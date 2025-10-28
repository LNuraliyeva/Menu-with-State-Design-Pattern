#ifndef ID_H
#define ID_H

#include "state.h"
#include "view.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

class ID : public State {
private:
    enum IDOptions {
        LINE_ONE = 0,
        LINE_TWO = 1
    };

    int current_index;
    std::vector<IDOptions> id_option;
    std::unordered_map<IDOptions, std::function<void()>> id_menu_actions;

public:
    ID(View* v);
    void button_up_pressed() override;
    void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // ID_H
