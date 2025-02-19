#include <iostream>
#include <string>
#include "include/main_menu.hpp"
#include "include/game_loop.hpp"
//init hats
AI hatAI;
hats hat;
//init toe
toes toe0;



int main(){      
    //start menu
    char mode = menu();
    //2 init hats
    hat.init_hat(mode, toe0);
    hatAI.init(hat);
    //info 
    main_info(hat, hatAI);
    // start game
    game_loop(hatAI, hat);
}
