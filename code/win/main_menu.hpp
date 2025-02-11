#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
std::string menu(){
        while(1){
            system("cls");
            std::cout << "\t\t\tPress Q to quit" << std::endl;
            std::cout << "\t\t\tPress P to play" << std::endl;
            char ch = getch();
            if(ch == 'q'){
                return "quit";
            }
            if(ch == 'p'){
                system("cls");
                std::cout << "Choice your HAT:";
                std::cout << "\n\nf=farmer hat, j = joker hat, s = santa hat";
                ch = getch();
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