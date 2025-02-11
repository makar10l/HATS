#include <iostream>
#include <string>
#include "libs/makar10l.hpp"
std::string menu(){
        while(1){
            system("clear");
            std::cout << "\t\t\tPress Q to quit" << std::endl;
            std::cout << "\t\t\tPress P to play" << std::endl;
            int ch = getch();
            if(ch == 113){
                return "quit";
            }
            if(ch == 112){
                system("clear");
                std::cout << "Choice your HAT:";
                std::cout << "\n\nf=farmer hat, j = joker hat, s = santa hat";
                ch = getch();
                switch(ch){
                    case 102:
                    return "farmer";
                    break;
                    case 106:
                    return "joker";
                    break;
                    case 115:
                    return "santa";
                    break;
                
                }
            }
        }
}