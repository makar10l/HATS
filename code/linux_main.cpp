#include <iostream>
#include <string>
#include "hat.hpp"
#include "getch.hpp"
#include "menu/main_menu.hpp"
int x;
int y;
int main(){
    hats my_hat;
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
      std::cout << "Enter DIRECTION:";
      std::cin >> dir;
      if(dir == 0 || dir == 1 || dir == 2 || dir == 3){
        coords xy = walk_to(dir);
        x = xy.x;
        y = xy.y;
      }
      else{
        toe.out();
        std::cout << "Enter DIRECTION bullet:";
        std::cin >> dir;
        my_hat.attack(10, x_y, dir);
      }
      toe.out(x,y);
    }
    return 0;
}
