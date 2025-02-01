#include "textures/textures.h"
#include "toe.hpp"
#include <unistd.h>

#define SPEED 500000
toe toe;
struct coords{
    int x = 1;
    int y = 1;
    int dir;
} x_y;
coords walk_to(int dir){
    x_y.dir = dir;
    switch(dir){
        case 0:
            if(x_y.y >= 2){
                toe.toe_e[x_y.y][x_y.x] = '.';
                x_y.y--;
            }
            break;
        case 1:
            if(x_y.y < 5){
                toe.toe_e[x_y.y][x_y.x] = '.';
                x_y.y++;
            }
            break;
        case 2:
            if(x_y.x >= 2){
                toe.toe_e[x_y.y][x_y.x] = '.';           
                x_y.x--;
            }
            break;
        case 3:
            if(x_y.x < 11){
                toe.toe_e[x_y.y][x_y.x] = '.';
                x_y.x++;
            }
            break;
        default:
        std::cout << "wrong dir";
    }
    return x_y;
}
class hats{   
    
public:
    void attack(int damage, coords x_y){
        switch(x_y.dir){
            case 0:
                for(int i = x_y.y - 1; i > 0; i--){
                    toe.toe_e[i][x_y.x] = '@';
                    usleep(SPEED);
                    toe.out(x_y.x, x_y.y);
                    toe.toe_e[i][x_y.x] = '.';
                }
            break;

            case 1:
                for(int i = x_y.y + 1; i < 6; i++){
                    toe.toe_e[i][x_y.x] = '@';
                    usleep(SPEED);
                    toe.out(x_y.x, x_y.y);
                    toe.toe_e[i][x_y.x] = '.';
                }
            break;

            case 2:
            for(int i = x_y.x - 1; i > 0; i--){
                toe.toe_e[x_y.y][i] = '@';
                usleep(SPEED);
                toe.out(x_y.x, x_y.y);
                toe.toe_e[x_y.y][i] = '.';
                
            }
            break;
        }
    }

    void break_hat(int* hp, int damage){
        *hp -= damage;
        std::cout << "Your HAT start broking, HP your HAT:" << *hp << std::endl;
    }  

    void info(int hp, int damage){
        std::cout << "\nYour HAT HP:" << hp << std::endl;
        std::cout << "Your HAT damage:" << damage << std::endl;
    }
    int safe(int hp){
            return hp;
    }
};

class farmer_hat: public hats{
    private:   
        int damage = 5;
    public:
        int hp = 75;

        const int damage_pub = damage;

        std::string texture = farm_hat;
        std::string texture_cp = farm_hat_copy;

        farmer_hat(){
            std::cout << "\t\tITS YOUR HAT" <<std::endl <<"\033[105m"<<texture_cp<<"\033[00m";
            info(hp, damage);
        }
        
};
class santa_hat: public hats{
    private:   
        int damage = 15;

    public:
        int hp = 25;

        const int damage_pub = damage;

        std::string texture = santas_hat;
        std::string texture_cp = santas_hat_copy;

        santa_hat(){
            std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
            info(hp, damage);
        }
};
class joker_hat: public hats{ 
    private:    
        int damage = 100; 

    public:
        int hp = 1;
        std::string texture = joke_hat;
        std::string texture_cp = joke_hat_copy;
        const int damage_pub = damage;

        joker_hat(){                        
            std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
            info(hp, damage);
        }
};