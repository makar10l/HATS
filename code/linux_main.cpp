#include <iostream>
#include <string>
#include "hat.hpp"
#include "getch/linux_getch.hpp"
#include "menu/main_menu.hpp"
int x;
int y;
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
    toe.out();
    while(1){
      
      int dir;
      std::cout << "Enter DIRECTIION:";
      std::cin >> dir;
      coords xy = walk_to(dir);
      x = xy.x;
      y = xy.y;
      toe.out(x,y);
    }
    return 0;
}
