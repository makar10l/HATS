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
struct coordsAI{
    int x = 11;
    int y = 15;  
} AIx_y;

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
        void attack(int damage, coordsAI AIx_y, int dir){
            switch(dir){
                case 0:
                    for(int i = AIx_y.y - 1; i > 0; i--){
                        toe.toe_e[i][AIx_y.x] = '@';
                        usleep(SPEED);
                        toe.out(AIx_y.x, AIx_y.y);
                        toe.toe_e[i][AIx_y.x] = '.';
                    }
                break;

                case 1:
                    for(int i = AIx_y.y + 1; i < 6; i++){
                        toe.toe_e[i][AIx_y.x] = '@';
                        usleep(SPEED);
                        toe.out(AIx_y.x, AIx_y.y);
                        toe.toe_e[i][AIx_y.x] = '.';
                    }
                break;

                case 2:
                    for(int i = AIx_y.x - 1; i > 0; i--){
                        toe.toe_e[AIx_y.y][i] = '@';
                        usleep(SPEED);
                        toe.out(AIx_y.x, AIx_y.y);
                        toe.toe_e[AIx_y.y][i] = '.';                
                    }
                break;

                case 3:
                    for(int i = AIx_y.x + 1; i < 12; i++){
                        toe.toe_e[AIx_y.y][i] = '@';
                        usleep(SPEED);
                        toe.out(AIx_y.x, AIx_y.y);
                        toe.toe_e[AIx_y.y][i] = '.'; 
                    }
                break;
            }
        }

    void break_hat(int* hp, int damage){
        *hp -= damage;
        std::cout << "Your HAT start broking, HP your HAT:" << *hp << std::endl;
    }  

    void info(int hp, int damage){
        std::cout << "\t\tTHIS IS YOUR HAT:\n\n" << texture_cp;
        std::cout << "\nYour HAT HP:" << hp << std::endl;
        std::cout << "Your HAT damage:" << damage << std::endl;
    }
}; 