#include "textures/textures.h"
#include "toe.hpp"
#include <unistd.h>
#include <ctime>
#define SPEED 500000
toe toe;
AI hatAI;
int AIx = hatAI.x;
int AIy = hatAI.y;
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
AI _return(){
    return hatAI;
}
class hats{      
    public:
        int hp;
        int damage;
        std::string texture;
        std::string texture_cp;
        void attack(int damage, int x, int y, short dir){
            switch(dir){
                case 0:
                    for(int i = y - 1; i > 0; i--){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx,AIy);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 1:
                    for(int i = x_y.y + 1; i < 6; i++){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx,AIy);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 2:
                    for(int i = x - 1; i > 0; i--){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx,AIy);
                        toe.toe_e[y][i] = '.';                
                    }
                break;

                case 3:
                    for(int i = x_y.x + 1; i < 12; i++){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx,AIy);
                        toe.toe_e[y][i] = '.'; 
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
class AI{
    public:
    int AIx;
    int AIy;
    int hp;
    int damage;
    std::string texture;
    std::string texture_cp;
    AI(){
        int texte = 0 + rand() % 2;
        switch(texte){
                case 0:
                    texture = farm_hat;
                    texture_cp = farm_hat_copy;
                    hp = 75;
                    damage = 5;
                
                case 1:
                    hp = 1;
                    texture = joke_hat;
                    texture_cp = joke_hat_copy;
                    damage = 100; 
                
                case 2:
                    texture = santas_hat;
                    texture_cp = santas_hat_copy;
                    hp = 25;
                    damage = 15;  
        } 
    }
    void attack(int damage, int x, int y, short dir){
            switch(dir){
                case 0:
                    for(int i = y - 1; i > 0; i--){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx,AIy);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 1:
                    for(int i = y + 1; i < 6; i++){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx, AIy);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 2:
                    for(int i = x - 1; i > 0; i--){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx, AIy);
                        toe.toe_e[y][i] = '.';                
                    }
                break;

                case 3:
                    for(int i = x + 1; i < 12; i++){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y, AIx, AIy);
                        toe.toe_e[y][i] = '.'; 
                    }
                break;
            }
        }
    char fight(){
        short dir;
        if(AIy == x_y.y){
            if(AIx > x_y.x){
                dir = 2;
            }
            if(AIx < x_y.x){
                dir = 3;
            }
        }
        else if(AIx == x_y.x){
            if(AIy > x_y.y){
                dir = 0;
            }
            if(AIy > x_y.y){
                dir = 1;
            }
        }
        std::cout << dir << ":DIR";
        hats::attack(damage, AIx, AIy, dir);       
    }
    
};