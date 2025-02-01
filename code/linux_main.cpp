#include <iostream>
#include <string>
#include "hat.hpp"
#include "getchar.hpp"
#include "menu/main_menu.hpp"

int x;
int y;
int main(){
    hats hat;
    std::string mode = menu();

    if(mode == "farmer"){
        farmer_hat hatk;        
    }

    if(mode == "joker"){
        joker_hat hatk;        
    }

    if(mode == "santa"){
        santa_hat hatk;        
    }

    getch();

    toe.out();

    while(1){
      hat.info(hat.hp, hat.damage);
      getch();
      int dir;
      toe.out();
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
        hat.attack(10, x_y, dir);
      }
      toe.out(x,y);
    }
    return 0;
}
