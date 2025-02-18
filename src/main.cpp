#include <iostream>
#include <string>
#include "include\main_menu.hpp"
#include "include\game_loop.hpp"
AI hatAI;
hats hat;
toes toe0;



int main(){      
    char mode = menu();
    hat.init_hat(mode, toe0);
    hatAI.init(hat);
    main_info(hat, hatAI);
    game_loop(hatAI, hat);
}
