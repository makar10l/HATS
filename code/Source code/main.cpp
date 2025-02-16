#include <iostream>
#include <string>
#include "main_menu.hpp"
#include "hat.hpp"

AI hatAI;
hats hat;

int x = 1;
int y = 1;
int direct;
int fight(toes toe){
  toe.out(x,y, hatAI.AIx,hatAI.AIy);
  std::cout << "Enter DIRECTION bullet:";
  std::cin >> direct;
  hat.attack(10, x, y, direct, 0);
  return 0;
}

int main(){
    toes toe0 = _return();
    toe0.out(x,y, hatAI.AIx,hatAI.AIy);   
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
      toe0.out(x,y, hatAI.AIx,hatAI.AIy);
      int dir;
      
      std::cout << "Choice DIRECTION:";
      std::cin >> dir;
      if(dir == 0 || dir == 1 || dir == 2 || dir == 3 && point < 1){
          coords xy = walk_to(dir);
          x = xy.x;
          y = xy.y;
          int guess;
          point++;
          toe0.out(x,y, hatAI.AIx, hatAI.AIy);
          std::cout << "\n\nDo you want to attack?(yes=1 no=0)?"; 
          std::cin >> guess;
          if(guess){            
            toe0.out(x,y, hatAI.AIx, hatAI.AIy);
            fight(toe0);
          }
      }
      else if(dir == 9){
        hat.info(hat.hp, hat.damage);
        getch();
        getch();        
        toe0.out(x,y,hatAI.AIx, hatAI.AIy);
      }
      else{
        fight(toe0);
        toe0.out(x,y,hatAI.AIx,hatAI.AIy);
      }
      hatAI.walkAI(toe0, y, x);
      toe0.out(x,y,hatAI.AIx,hatAI.AIy);
    }
}
