#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "state.h"
#include "view.h"
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

class Power;
class Wifi;
class ID;

class Dashboard : public State {
private:
    std::vector<std::string> options;
    int current_index;
    std::unordered_map<int, std::function<void()>> actions;
    
public:
    Dashboard(View* v);

    void button_up_pressed() override;
    void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // DASHBOARD_H
