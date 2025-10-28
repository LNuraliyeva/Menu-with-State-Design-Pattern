#include "display.h"
#include <iostream>

void Display::show(FieldStrings field_strings) {
    
    std::cout << "Flash status" << std::endl;
    std::cout <<  (field_strings.highlighted[0] ? 
                    field_strings.field_one_string + " <<< " : field_strings.field_one_string) << std::endl;
    std::cout <<  (field_strings.highlighted[1] ? 
                    field_strings.field_two_string + " <<< " : field_strings.field_two_string) << std::endl;  
    std::cout <<  (field_strings.highlighted[2] ? 
                    field_strings.field_three_string + " <<< " : field_strings.field_three_string) << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "";
}