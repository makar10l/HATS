#include <iostream>
#include <string>
#include "windows.h"
std::string menu(){
        while(1){
            system("clear");
            std::cout << "\t\t\tPress Q to quit" << std::endl;
            std::cout << "\t\t\tPress P to play" << std::endl;
            int ch = _getch();
            if(ch == 'q'){
                return "quit";
            }
            if(ch == 112){
                system("clear");
                std::cout << "Choice your HAT:";
                std::cout << "\n\nf=farmer hat, j = joker hat, s = santa hat";
                ch = _getch();
                switch(ch){
                    case 'f':
                    return "farmer";
                    break;
                    case 'j':
                    return "joker";
                    break;
                    case 's':
                    return "santa";
                    break;
                
                }
            }
        }
}