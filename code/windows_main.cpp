#include <iostream>
#include <string>
#include "hat.hpp"
#include "menu/windows_main_menu.hpp"
#include "textures/toe.hpp"
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
    toe.out(x,y);
    x,y = walk_to(1,x,y);
    std::cout << x << "   " << y;
    getch();
    toe.out(x,y);
    return 0;
}