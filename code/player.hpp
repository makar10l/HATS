#include "toe.hpp"
toe toe;
int walk_to(int dir, ixcnt x, int y){
    switch(dir){
        case 0:
            toe.toe_e[y][x] = '.';
            y--;
            break;
        case 1:
            toe.toe_e[y][x] = '.';
            y++;
            break;
        case 2:
            toe.toe_e[y][x] = '.';
            x--;
            break;
        case 3:
            toe.toe_e[y][x] = '.';
            x++;
            break;
        default:
        std::cout << "wrong dir";
    }
    return x, y;
}