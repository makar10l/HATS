#include <iostream>
#include <string>
#include "libs/makar10l.cpp"
#include "hat.hpp"
const float speed_menu = 1.0;
char menu(){
        while(1){
            clear();
            std::cout << "\t\t\tPress Q to quit" << std::endl;
            std::cout << "\t\t\tPress P to play" << std::endl;
            #ifdef WIN32
                char ch = getch();
                if(ch == 'q'){
                    return 'q';
                }
                if(ch == 'p'){
                    clear();
                    std::cout << "\t\tMOVEMENT:\n\n";
                    std::cout << "\t\t     0    \n";
                    std::cout << "\t\t     ^    \n";
                    std::cout << "\t\t2  < | > 3   \n";
                    std::cout << "\t\t     ^    \n";
                    std::cout << "\t\t     1    \n";
                    std::cout << "\t\t GUN -> 5\n";
                    getch();
                    clear();
                    std::cout << "Choice your HAT:";
                    std::cout << "\n\nf=farmer hat, j = joker hat, s = santa hat";
                    ch = getch();
                    switch(ch){
                        case 'f':
                        return 'f';
                        break;
                        case 'j':
                        return 'j';
                        break;
                        case 's':
                        return 's';
                        break;
                    
                    }
                }
            #else
                int ch = getch();
                if(ch == 113){
                    return 'q';
                }
                if(ch == 112){
                    clear();
                    std::cout << "\t\tMOVEMENT:\n\n";
                    std::cout << "\t\t     0    \n";
                    std::cout << "\t\t     ^    \n";
                    std::cout << "\t\t2  < | > 3  \n";
                    std::cout << "\t\t     ^    \n";
                    std::cout << "\t\t     1    \n";
                    std::cout << "\t\t GUN -> 5\n";
                    getch();
                    clear();
                    std::cout << "Choice your HAT:";
                    std::cout << "\n\nf=farmer hat, j = joker hat, s = santa hat";
                    ch = getch();
                    switch(ch){
                        case 102:
                        return 'f';
                        break;
                        case 106:
                        return 'j';
                        break;
                        case 115:
                        return 's';
                        break;
                    
                    }
                }
            #endif
            
        }
}
void main_info(hats hat, AI hatAI){
    clear();
    std::cout << "\t\tINFO:\n\n";
    sleep(speed_menu);
    print("ITS YOUR HAT\n\n");
    hat.info(hat.hp, hat.damage);
    sleep(speed_menu);
    clear();
    print("ITS AI HAT\n\n");
    hatAI.info();
    sleep(speed_menu);
}