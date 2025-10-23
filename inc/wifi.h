#ifndef WIFI_H
#define WIFI_H

#include "state.h"
#include "view.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

class Wifi : public State {
private:
    enum WifiOptions {
        LINE_ONE = 0,
        LINE_TWO = 1
    };

    int current_index;
    std::vector<WifiOptions> wifi_option;
    std::unordered_map<WifiOptions, std::function<void()>> wifi_menu_actions;

public:
    Wifi(View* v);
    void button_up_pressed() override;
    void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // WIFI_H
