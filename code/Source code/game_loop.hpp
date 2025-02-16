void game_loop(AI hatAI, hats hat){
    int x = 1;
    int y = 1;
    int direct;
    while(1){
        hatAI.upd(hat);
        int point = 0;
        hat.toe.toe_e[hatAI.AIy][hatAI.AIx] = '*';
        hat.toe.out();
        int dir;
        std::cout << "Choice DIRECTION:";
        std::cin >> dir;
        if(dir == 0 || dir == 1 || dir == 2 || dir == 3 && point < 1){
            coords xy = hat.walk_to(dir);
            x = xy.x;
            y = xy.y;
            int guess;
            point++;
            hat.toe.out();
            std::cout << "\n\nDo you want to attack?(yes=1 no=0)?"; 
            std::cin >> guess;
            if(guess){            
              hat.toe.out();
              fight(hat, x,y);
            }
        }
        else{
          fight(hat, x,y);
          hat.toe.out();
        }
        hatAI.upd(hat);
        hatAI.walkAI(y, x);
        hat.toe.out();
      }
}