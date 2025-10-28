#include "display.h"
#include <iostream>

void Display::show(){
    
    std::cout << "Flash status" << std::endl;
    std::cout <<  (current_state->field_strings.field_one_highlighted ? 
                    current_state->field_strings.field_one_string + " <<< " : current_state->field_strings.field_one_string) << std::endl;
    std::cout <<  (current_state->field_strings.field_two_highlighted ? 
                    current_state->field_strings.field_two_string + " <<< " : current_state->field_strings.field_two_string) << std::endl;  
    std::cout <<  (current_state->field_strings.field_three_highlighted ? 
                    current_state->field_strings.field_three_string + " <<< " : current_state->field_strings.field_three_string) << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << "";
}