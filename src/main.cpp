#include <iostream>
#include "main.h"

using namespace std;

int main() {
  Context *context;
  FieldStrings field_strings_camera1; // it is not a pointer because of the strings does not have allocated memory yet
  std::string command;

  set_field(field_strings_camera1, "device_number", "123");
  set_field(field_strings_camera1, "flash1", "FlashX ");
  set_field(field_strings_camera1, "HW_version", "1.0.0");
  set_field(field_strings_camera1, "SW_version", "2.1.3");
  set_field(field_strings_camera1, "checksum", "ABCDEF123456");
  set_field(field_strings_camera1, "flash_count", "1500");
  set_field(field_strings_camera1, "flash_count_last", "1450");
  set_field(field_strings_camera1, "battery1_time_left", "2h 30m");
  set_field(field_strings_camera1, "battery2_time_left", "3h 15m");
  set_field(field_strings_camera1, "barrety1", "75%");
  set_field(field_strings_camera1, "battery2", "85%");
  set_field(field_strings_camera1, "flash_intencity", "75%");
  set_field(field_strings_camera1, "wifi", "on");
  set_field(field_strings_camera1, "ism", "on");

Dashboard *dashboard = new Dashboard(context, field_strings_camera1);
  
  Power *power = new Power(context, field_strings_camera1);
  ID *id = new ID(context, field_strings_camera1);
  Wifi *wifi = new Wifi(context, field_strings_camera1);
  context = new Context(dashboard);

  id->setParent(dashboard);
  power->setParent(dashboard);
  wifi->setParent(dashboard);
  dashboard->setChild[0](wifi);
  dashboard->setChild[1](power);
  dashboard->setChild[2](id);

context->display();

  while(true){
    cin >> command;
    if(command == "up"){
      context->press_up();
      context->display();
    } else if(command == "down"){
      context->press_down();
      context->display();
    } else if(command == "select"){
      context->press_select();
      context->display();
    } else if(command == "exit"){
      break;
    }
  }
  return 0;
}