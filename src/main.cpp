#include <iostream>
#include "main.h"

using namespace std;

int main() {
  View *view;
  FieldStrings field_strings; // it is not a pointer because of the strings does not have allocated memory yet
  Dashboard *dashboard = new Dashboard(view, field_strings);
  
  Power *power = new Power(view, field_strings);
  ID *id = new ID(view, field_strings);
  Wifi *wifi = new Wifi(view, field_strings);
  view = new View(dashboard);
  //Display screen;
  
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

  view->display();
  std::string command;

  while(true){
    cin >> command;
    if(true){
      view->press_up();
      view->display();
      break;
    } else if(command == "down"){
      view->press_down();
      view->display();
    } else if(command == "select"){
      view->press_select();
      view->display();
    } else if(command == "exit"){
      break;
    }
  }
  return 0;
}