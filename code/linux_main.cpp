#include <iostream>
#include <string>
#include "hat.hpp"
#include "getch/linux_getch.hpp"
#include "menu/main_menu.hpp"
#include "toe.hpp"
#include "player.hpp"
int x = 1;
int y = 1;
int main(){
    std::string mode = menu();
    if(mode == "farmer"){
        farmer_hat my_hat;        
    }
      if(mode == "joker"){
        joker_hat my_hat;        
    }
      if(mode == "santa"){
        santa_hat my_hat;        
    }
    std::cout << "EGGS";
    player player;
    toe toe;
    toe.out(x,y);
    player.walk_to(2,2,&x,&y);
    std::cout << x << "   " << y;
    // toe.out(x,y);
    return 0;
}
