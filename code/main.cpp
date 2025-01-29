#include <iostream>
#include <string>
#include "hat.hpp"

int main(){
    joker_hat my_hat;
    my_hat.break_hat(my_hat.hp, 20);
    my_hat.attack(my_hat.damage_pub);
    my_hat.hp++;
    std::cout << my_hat.hp;
    return 0;
}