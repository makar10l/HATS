#include "textures/textures.h"
#include "toe.hpp"
#include <ctime>
const float SPEED = 0.1;
int modegunAI;
struct coords{
    int x = 1;
    int y = 1;  
    int dir;
} x_y;   

class hats{      
    public:
        toes toe;
        int hp;
        int damage;
        int modegun;
        std::string texture;
        std::string texture_cp;
        void init_hat(char _hat, toes toe0){
            switch(_hat){
                case 'f':
                    texture = farm_hat;
                    texture_cp = farm_hat_copy;
                    hp = 75;
                    damage = 5;
                    modegun = 0;
                break;

                case 'j':
                    hp = 1;
                    texture = joke_hat;
                    texture_cp = joke_hat_copy;
                    damage = 100;        
                    modegun = 0;
                break;
                case 's':
                    texture = santas_hat;
                    texture_cp = santas_hat_copy;
                    hp = 25;
                    damage = 15; 
                    modegun = 1;
                break;
            }
            toe = toe0;
        }
        void attack_long(int damage, int x, int y, int dir){
            switch(dir){
                case 0:
                    for(int i = y - 1; i > 0; i--){
                        toe.toe_e[i][x] = '@';                       
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                        sleep(SPEED);
                    }
                break;

                case 1:
                    for(int i = y + 1; i < Y_SIZE-1; i++){
                        toe.toe_e[i][x] = '@';                       
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                        sleep(SPEED);
                    }
                break;
                case 2:
                    for(int i = x - 1; i > 0; i--){
                        toe.toe_e[y][i] = '@';                        
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.';
                        sleep(SPEED);                
                    }
                break;

                case 3:
                    for(int i = x + 1; i < X_SIZE-1; i++){
                        toe.toe_e[y][i] = '@';                       
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.';
                        sleep(SPEED); 
                    }
                break;
            }
        }
        void attack_short(int damage, int x, int y, int dir){
            switch(dir){
                case 0:
                    for(int i = y - 1; i >= y-2; i--){
                        toe.toe_e[i][x] = '@';                       
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                        sleep(SPEED);
                        
                    }
                break;

                case 1:
                    for(int i = x_y.y + 1; i <= y+2; i++){
                        toe.toe_e[i][x] = '@';                        
                        toe.out(x, y);
                        toe.toe_e[i][x] = '.';
                        sleep(SPEED);
                    }
                break;

                case 2:
                    for(int i = x - 1; i >= x-2; i--){
                        toe.toe_e[y][i] = '@';                       
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.';
                        sleep(SPEED);                
                    }
                break;

                case 3:
                    for(int i = x_y.x + 1; i <= x+2; i++){
                        toe.toe_e[y][i] = '@';
                        toe.out(x, y);
                        toe.toe_e[y][i] = '.'; 
                        sleep(SPEED);
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
         
        coords walk_to(int dir){
            x_y.dir = dir;
            switch(dir){
                case 0:
                    if(x_y.y >= 2){
                        toe.toe_e[x_y.y][x_y.x] = '.';
                        x_y.y--;
                        toe.toe_e[x_y.y][x_y.x] = '0';
                    }
                    break;
                case 1:
                    if(x_y.y < Y_SIZE-2){
                        toe.toe_e[x_y.y][x_y.x] = '.';
                        x_y.y++;
                        toe.toe_e[x_y.y][x_y.x] = '0';
                    }
                    break;
                case 2:
                    if(x_y.x >= 2){
                        toe.toe_e[x_y.y][x_y.x] = '.';           
                        x_y.x--;
                        toe.toe_e[x_y.y][x_y.x] = '0';
                    }
                    break;
                case 3:
                    if(x_y.x < X_SIZE-2){
                        toe.toe_e[x_y.y][x_y.x] = '.';
                        x_y.x = x_y.x + 1;
                        toe.toe_e[x_y.y][x_y.x] = '0';
                    }
                    break;
                default:
                std::cout << "wrong dir";
            }
            return x_y;
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
    hats hat;
    int AIx = 11;
    int AIy = 5;
    int hp;
    int damage;
    void info(){
        std::cout << "\t\tTHIS IS YOUR HAT:\n\n" << texture_cp;
        std::cout << "\nYour HAT HP:" << hp << std::endl;
        std::cout << "Your HAT damage:" << damage << std::endl;
    }
    std::string texture;
    std::string texture_cp;
    void init(hats hat0){
        int texte;
        bool textur = true;
        while(textur){
        srand(time(0));
        texte = 0 + rand() % 4;
        switch(texte){
                case 1:
                    texture = farm_hat;
                    texture_cp = farm_hat_copy;
                    hp = 75;
                    damage = 5;
                    textur = !textur;
                    modegunAI = 0;
                    break;
                case 2:
                    hp = 1;
                    texture = joke_hat;
                    texture_cp = joke_hat_copy;
                    damage = 100; 
                    textur = !textur;
                    modegunAI = 0;
                    break;
                case 3:
                    texture = santas_hat;
                    texture_cp = santas_hat_copy;
                    hp = 25;
                    damage = 15;
                    textur = !textur;
                    modegunAI = 1;
                    break;                 
            } 
        }
        hat = hat0;
        hat.toe.toe_e[Y_SIZE-1][X_SIZE-1] = '*';
    }
    void upd(hats hat0){
        hat = hat0;
    }
    void attack_long(int damage, int x, int y, int dir){
        switch(dir){
            case 0:
                for(int i = y - 1; i > 0; i--){
                    hat.toe.toe_e[i][x] = '@';                       
                    hat.toe.out();
                    hat.toe.toe_e[i][x] = '.';
                    sleep(SPEED);
                }
            break;

            case 1:
                for(int i = y + 1; i < Y_SIZE-1; i++){
                    hat.toe.toe_e[i][x] = '@';                       
                    hat.toe.out();
                    hat.toe.toe_e[i][x] = '.';
                    sleep(SPEED);
                }
            break;
            case 2:
                for(int i = x - 1; i > 0; i--){
                    hat.toe.toe_e[y][i] = '@';                        
                    hat.toe.out();
                    hat.toe.toe_e[y][i] = '.';
                    sleep(SPEED);                
                }
            break;

            case 3:
                for(int i = x + 1; i < 12; i++){
                    hat.toe.toe_e[y][i] = '@';                       
                    hat.toe.out();
                    hat.toe.toe_e[y][i] = '.';
                    sleep(SPEED); 
                }
            break;
        }
    }
    void attack_short(int damage, int x, int y, int dir){
        switch(dir){
            case 0:
                for(int i = y - 1; i >= y-2; i--){
                    hat.toe.toe_e[i][x] = '@';                       
                    hat.toe.out();
                    hat.toe.toe_e[i][x] = '.';
                    sleep(SPEED);
                    
                }
            break;

            case 1:
                for(int i = x_y.y + 1; i <= y+2; i++){
                    hat.toe.toe_e[i][x] = '@';                        
                    hat.toe.out();
                    hat.toe.toe_e[i][x] = '.';
                    sleep(SPEED);
                }
            break;

            case 2:
                for(int i = x - 1; i >= x-2; i--){
                    hat.toe.toe_e[y][i] = '@';                       
                    hat.toe.out();
                    hat.toe.toe_e[y][i] = '.';
                    sleep(SPEED);                
                }
            break;

            case 3:
                for(int i = x_y.x + 1; i <= x+2; i++){
                    hat.toe.toe_e[y][i] = '@';
                    hat.toe.out();
                    hat.toe.toe_e[y][i] = '.'; 
                    sleep(SPEED);
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
    void walkAI(int y, int x){
        int cloneY = AIy;
        int cloneX = AIx;
        if(y < AIy){
            for(; cloneY > 0; cloneY--){
                for(int x = AIx; x > 0; x--){
                    if(hat.toe.toe_e[cloneY][x] == '0')
                    {
                        if(AIy == cloneY){
                            attack(damage, AIx, AIy, 2, modegunAI);
                        }
                        else{
                            AIy--;
                        }
                    }
                }
            }
        }
        else if(y > AIy){
            for(; cloneY < 6; cloneY++){
                for(int x = AIx; x > 0; x--){
                    if(hat.toe.toe_e[cloneY][x] == '0')
                    {
                            if(AIy == cloneY){
                                attack(damage, AIx, AIy, 2, modegunAI);
                            }
                            else{
                                AIy++;
                            }
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
int fight(hats hat, int x, int y){
    int direct;
    hat.toe.out();
    std::cout << "Enter DIRECTION bullet:";
    std::cin >> direct;
    hat.attack(10, x, y, direct, hat.modegun);
    return 0;
  }