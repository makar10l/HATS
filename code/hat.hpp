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
        int hp;
        int damage;
        std::string texture;
        std::string texture_cp;
        void attack(int damage, coords x_y, int dir){
            switch(dir){
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

                case 3:
                    for(int i = x_y.x + 1; i < 12; i++){
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
    public:
        farmer_hat(){
            hats::texture = farm_hat;
            hats::texture_cp = farm_hat_copy;
            hats::hp = 75;
            hats::damage = 5;
            std::cout << "\t\tITS YOUR HAT" <<std::endl <<"\033[105m"<<hats::texture_cp<<"\033[00m";
            info(hats::hp, hats::damage);
           
        }
        
};
class santa_hat: public hats{ 
    public:       
        santa_hat(){
            hats::texture = santas_hat;
            hats::texture_cp = santas_hat_copy;
            hats::hp = 25;
            hats::damage = 15;
            std::cout << "\t\tITS YOUR HAT" << std::endl  << hats::texture_cp;
            info(hats::hp, hats::damage);
            
        }
};
class joker_hat: public hats{ 
    public:
        joker_hat(){
            hats::hp = 1;
            hats::texture = joke_hat;
            hats::texture_cp = joke_hat_copy;
            hats::damage = 100;                         
            std::cout << "\t\tITS YOUR HAT" << std::endl  << hats::texture_cp;
            info(hats::hp, hats::damage);
            
        }
};