#include <iostream>
#include <string>
#include "hat.hpp"
#include "getchar.hpp"
#include "menu/main_menu.hpp"
hats hat;
int x;
int y;
int direct;
int fight(){
  toe.out(x,y);
  std::cout << "Enter DIRECTION bullet:";
  std::cin >> direct;
  hat.attack(10, x_y, direct);
  return 0;
}
int main(){
    
    std::string mode = menu();

    if(mode == "farmer"){
        hat.texture = farm_hat;
        hat.texture_cp = farm_hat_copy;
        hat.hp = 75;
        hat.damage = 5;        
    }

    if(mode == "joker"){
        hat.hp = 1;
        hat.texture = joke_hat;
        hat.texture_cp = joke_hat_copy;
        hat.damage = 100;        
    }

    if(mode == "santa"){
        hat.texture = santas_hat;
        hat.texture_cp = santas_hat_copy;
        hat.hp = 25;
        hat.damage = 15;       
    }

    while(1){
      int point = 0;
      toe.out();
      int dir;
      std::cout << "Choice DIRECTION:";
      std::cin >> dir;
      if(dir == 0 || dir == 1 || dir == 2 || dir == 3 && point < 1){
        coords xy = walk_to(dir);
        x = xy.x;
        y = xy.y;
        point++;
        int guess;
        toe.out(x,y);
        std::cout << "\n\nDo you want to attack?(yes=1 no=0)?"; 
        std::cin >> guess;
        if(guess){
          fight();
          toe.out(x,y);
        }
      }
      else if(dir == 9){
        hat.info(hat.hp, hat.damage);
        getch();
        getch();        
        toe.out(x,y);
      }
      else{
        fight();
        toe.out(x,y);
      }
      toe.out(x,y);
    }
    return 0;
}
