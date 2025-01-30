#include <iostream>
#include <string>
#include "hat.hpp"
#include "getch/linux_getch.hpp"
#include "menu/main_menu.hpp"

int main(){
   
    int PorQ = menu();
    if(PorQ == 0){
        farmer_hat my_hat;
        int hp = my_hat.safe(my_hat.hp);
        my_hat.break_hat(&hp, 20);
        my_hat.attack(my_hat.damage_pub);
        hp++;
        std::cout << hp;
    }
    else{
        return 1;
    }
    return 0;
}
