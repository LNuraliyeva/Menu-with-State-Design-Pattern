#ifndef WIFI_H
#define WIFI_H

#include "state.h"
#include "context.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

class Wifi : public State {
private:
    
    std::unordered_map<int, std::function<void()>> wifi_menu_actions;
public:
    Wifi(Context* context, FieldStrings field_strings);
    // void button_up_pressed() override;
    // void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // WIFI_H
