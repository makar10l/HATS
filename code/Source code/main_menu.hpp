#include <iostream>
#include <string>
#include "libs/makar10l.cpp"
std::string menu(){
        while(1){
            clear();
            std::cout << "\t\t\tPress Q to quit" << std::endl;
            std::cout << "\t\t\tPress P to play" << std::endl;
            #ifdef WIN32
                char ch = getch();
                if(ch == 'q'){
                    return "quit";
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
            #else
                int ch = getch();
                if(ch == 113){
                    return "quit";
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
            #endif
            
        }
}