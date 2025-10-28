#include <iostream>
#include "main.h"

using namespace std;

int main() {
  View *view;
  
  Dashboard *dashboard = new Dashboard(view);
  Wifi *wifi = new Wifi(view);
  Power *power = new Power(view);
  ID *id = new ID(view);
  view = new View(dashboard);
  Display screen;
// page.view = view
// page1.field1 = myfunction -> go to page 2
// page1.field2  = []
// page.field3  = myfunction2 -> go Back
//
// page.display() -> print(Fielf1, field2, field3 , ...)

// view.add(Page)
// 
  id->setParent(dashboard);
  power->setParent(dashboard);
  wifi->setParent(dashboard);
  dashboard->setChild[0](wifi);
  dashboard->setChild[1](power);
  dashboard->setChild[2](id);

  std::string command;

  while(true){
    cin >> command;
    if(command == "up"){
      view->press_up();
      screen.show();
    } else if(command == "down"){
      view->press_down();
      screen.show();
    } else if(command == "select"){
      view->press_select();
      screen.show();
    } else if(command == "exit"){
      break;
    }
  }
  return 0;
}