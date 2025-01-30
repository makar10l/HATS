#include <iostream>


int menu(){
        std::cout << "\t\t\tPress Q to quit" << std::endl;
        std::cout << "\t\t\tPress P to play" << std::endl;
        int ch = getch();
        switch (ch){
            case 113:
                return 1;
                break;
            case 112:
                return 0;
        }
        std::cout << ch;
}