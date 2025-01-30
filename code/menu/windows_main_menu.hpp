#include <iostream>
#include <windows.h>
#include <conio.h>

int menu(){
        std::cout << "\t\t\tPress Q to quit" << std::endl;
        std::cout << "\t\t\tPress P to play" << std::endl;
        char ch = getch();
        switch (ch){
            case 'q':
                return 1;
                break;
            case 'p':
                return 0;
        }
        std::cout << ch;
}