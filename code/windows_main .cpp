#include <iostream>
#include <string>
#include "hats\hat.hpp"

int main(){
    farmer_hat my_hat;
    int hp = my_hat.safe(my_hat.hp);
    my_hat.break_hat(&hp, 20);
    my_hat.attack(my_hat.damage_pub);
    hp++;
    std::cout << hp;
    return 0;
}
