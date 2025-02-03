#include "textures/textures.h"
#include "toe.hpp"
#include <unistd.h>
#include <ctime>
#define X_SIZE 13
#define Y_SIZE 7

#define SPEED 500000
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
        void attack(int damage, int x, int y, short dir){
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
    void fight(){
        short dir;
        if(AIy == x_y.y){
            if(AIx > x_y.x){
                dir = 2;
                attack(damage, AIx, AIy, dir);
            }
            if(AIx < x_y.x){
                dir = 3;
                attack(damage, AIx, AIy, dir);
            }
        }
        else if(AIx == x_y.x){
            if(AIy > x_y.y){
                dir = 0;
                attack(damage, AIx, AIy, dir);
            }
            if(AIy > x_y.y){
                dir = 1;
                attack(damage, AIx, AIy, dir);
            }
        }       
    }
    short search_dir(int plX, int plY, int AIx, int AIy){
        short dir = 999;
        if(AIy == plY){
            if(AIx > plX){
                dir = 2;
            }
            if(AIx < plX){
                dir = 3;
            }
        }
        else if(AIx == plX){
            if(AIy > plY){
                dir = 0;
            }
            if(AIy > plY){
                dir = 1;

            }
        }  
        return dir;     
    }
    int walkAI(int playerX, int playerY){
        int dir1;
        short dir = search_dir(playerX, playerY, AIx, AIy);
        if(dir != 999){
            fight();
        }
        else{
            char copy_toe[Y_SIZE-2][X_SIZE-2];
            for(int y = 1; y < Y_SIZE-1; y++){
                for(int x = 1; x < X_SIZE-1; x++){
                    copy_toe[y][x] = toe.toe_e[y][x];
                }
            }
            short copyX = AIx;
            short copyY = AIy;
            if(copyX <= X_SIZE-2 || copyX != 0){
                if(copyX < X_SIZE - 3){
                    copyX++;                   
                    switch(search_dir(playerX,playerY, copyX, copyY)){
                        case 0:
                            dir1 = 0;
                            return dir1;
                        break;
                        case 1:
                            dir1 = 1;
                            return dir1;
                        break;
                        case 2:
                            dir1 = 2;
                            return dir1;
                        break;
                        case 3:
                            dir1 = 3;
                            return dir1;
                        break;
                       
                    }
                    copyX--;                    
                    switch(search_dir(playerX,playerY, copyX, copyY)){
                        case 0:
                            dir1 = 0;
                            return dir1;
                        break;
                        case 1:
                            dir1 = 1;
                            return dir1;
                        break;
                        case 2:
                            dir1 = 2;
                            return dir1;
                        break;
                        case 3:
                            dir1 = 3;
                            return dir1;
                        break;
                    }
                }

                copyX++;                   
                switch(search_dir(playerX,playerY, copyX, copyY)){
                    case 0:
                        dir1 = 0;
                        return dir1;
                    break;
                    case 1:
                        dir1 = 1;
                        return dir1;
                    break;
                    case 2:
                        dir1 = 2;
                        return dir1;
                    break;
                    case 3:
                        dir1 = 3;
                        return dir1;
                    break;
                    
                }
            }
            if(copyY <= Y_SIZE-2 || copyY != 0){
                if(copyY < Y_SIZE - 3){
                    copyY++;                   
                    switch(search_dir(playerX,playerY, copyX, copyY)){
                        case 0:
                            dir1 = 0;
                            return dir1;
                        break;
                        case 1:
                            dir1 = 1;
                            return dir1;
                        break;
                        case 2:
                            dir1 = 2;
                            return dir1;
                        break;
                        case 3:
                            dir1 = 3;
                            return dir1;
                        break;
                       
                    }
                    copyY--;                    
                    switch(search_dir(playerX,playerY, copyX, copyY)){
                        case 0:
                            dir1 = 0;
                            return dir1;
                        break;
                        case 1:
                            dir1 = 1;
                            return dir1;
                        break;
                        case 2:
                            dir1 = 2;
                            return dir1;
                        break;
                        case 3:
                            dir1 = 3;
                            return dir1;
                        break;
                    }
                }

                copyY++;                   
                switch(search_dir(playerX,playerY, copyX, copyY)){
                    case 0:
                        dir1 = 0;
                        return dir1;
                    break;
                    case 1:
                        dir1 = 1;
                        return dir1;
                    break;
                    case 2:
                        dir1 = 2;
                        return dir1;
                    break;
                    case 3:
                        dir1 = 3;
                        return dir1;
                    break;
                    
                }
            }
            }
            
        }       
        
};