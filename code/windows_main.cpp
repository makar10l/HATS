#include <iostream>
#include <string>
#include "hat.hpp"
#include "menu/windows_main_menu.hpp"
#include "textures/toe.hpp"
int main(){
    int PorQ = menu();
    if(PorQ == 0){
        farmer_hat my_hat;
        getch();
        for(int y = 0; y < Y_SIZE; y++){
            for(int x = 0; x < X_SIZE; x++){
                std::cout << toe[y][x];
            }
            std::cout << "\n";
        }
    }
    else{
        return 1;
    }
    return 0;
}
