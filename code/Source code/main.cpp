#include <iostream>
#include <string>
#include "main_menu.hpp"
#include "hat.hpp"
int main(){
    toes toe0 = _return();
    toe0.toe_e[1][1] = '0';
    walk_to(1);
    toe0.out();
    // toe0.toe_e[1][1] = '.';
    // toe0.toe_e[1][2] = '0';
    toe0.out();
}
