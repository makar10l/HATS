#include "toe.hpp"
toe toe;
struct coords{
    int x = 0;
    int y = 0;
} x_y;
coords walk_to(int dir){
    switch(dir){
        case 0:
            toe.toe_e[x_y.y][x_y.x] = '.';
            x_y.y--;
            break;
        case 1:
            toe.toe_e[x_y.y][x_y.x] = '.';
            x_y.y++;
            break;
        case 2:
            toe.toe_e[x_y.y][x_y.x] = '.';           
            x_y.x--;
            break;
        case 3:
            toe.toe_e[x_y.y][x_y.x] = '.';
            x_y.x++;
            break;
        default:
        std::cout << "wrong dir";
    }
    return x_y;
}