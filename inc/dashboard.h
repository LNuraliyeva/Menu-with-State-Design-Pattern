#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "state.h"
#include "context.h"
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

class Dashboard : public State {
private:
    // std::vector<std::string> options;
    std::unordered_map<int, std::function<void()>> actions;
public:
    Dashboard(Context* context, FieldStrings field_strings);
    // void button_up_pressed() override;
    // void button_down_pressed() override;
    void button_select_pressed() override;
};

#endif // DASHBOARD_H
