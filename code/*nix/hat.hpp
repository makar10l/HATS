#include "textures/textures.h"
#include "toe.hpp"
#include <unistd.h>
#include <ctime>
#define X_SIZE 13
#define Y_SIZE 7

toes toe;
struct coords{
    int x = 1;
    int y = 1;  
    int dir;
} x_y;   

toes _return(){
    return toe;
} 
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
        void attack_long(int damage, int x, int y, int dir){
            switch(dir){
                case 0:
                    for(int i = y - 1; i > 0; i--){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 1:
                    for(int i = x_y.y + 1; i < 6; i++){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 2:
                    for(int i = x - 1; i > 0; i--){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.';                
                    }
                break;

                case 3:
                    for(int i = x_y.x + 1; i < 12; i++){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.'; 
                    }
                break;
            }
        }
        void attack_short(int damage, int x, int y, int dir){
            switch(dir){
                case 0:
                    for(int i = y - 1; i > y-3; i--){
                        toe.toe_e[i][x] = '@';                       
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                        usleep(SPEED);
                    }
                break;

                case 1:
                    for(int i = x_y.y + 1; i > i+2; i++){
                        toe.toe_e[i][x] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                    }
                break;

                case 2:
                    for(int i = x - 1; i > i-2; i--){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.';                
                    }
                break;

                case 3:
                    for(int i = x_y.x + 1; i < i+2; i++){
                        toe.toe_e[y][i] = '@';
                        usleep(SPEED);
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.'; 
                    }
                break;
            }
        }
        void attack(int damage, int x, int y, short dir, short mode){
            if(mode == 1){
                attack_long(damage, x, y, dir);
            }
            if(mode == 0){
                attack_short(damage, x, y, dir);
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
    int AIx = 11;
    int AIy = 5;
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
    char walkAI(toes toe, int y, int x){
        int cloneY = AIy;
        int cloneX = AIx;
        if(y < AIy){
            for(; cloneY > 0; cloneY--){
                for(int x = AIx; x > 0; x--){
                    if(toe.toe_e[cloneY][x] == '0')
                    {
                        // if(AIy == cloneY){
                        //     attack(damage, AIx, AIy, 2);
                        // }
                        // else{
                            AIy--;
                        // }
                    }
                }
            }
        }
        else if(y > AIy){
            for(; cloneY < 6; cloneY++){
                for(int x = AIx; x > 0; x--){
                    if(toe.toe_e[cloneY][x] == '0')
                    {
                            // if(AIy == cloneY){
                            //     attack(damage, AIx, AIy, 2);
                            // }
                            // else{
                                AIy++;
                            // }
                    }
                }
            }
        }
        else if(x > cloneX){
            AIx++;
        } 
        else if(x < cloneX){
            AIx--;
        } 
    }
};
