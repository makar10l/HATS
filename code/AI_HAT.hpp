
class AI : public hats{
    public:
    int x;
    int y;
    AI(){
        int texte = 0 + rand() % 2;
        switch(texte){
                case 0:
                    texture = farm_hat;
                    texture_cp = farm_hat_copy;
                    hp = 75;
                    damage = 5;
                
                case 1:
                    hp = 1;
                    texture = joke_hat;
                    texture_cp = joke_hat_copy;
                    damage = 100; 
                
                case 2:
                    texture = santas_hat;
                    texture_cp = santas_hat_copy;
                    hp = 25;
                    damage = 15;  
        } 
    }
    char fight(){
        short dir;
        if(y == x_y.y){
            if(x > x_y.x){
                dir = 2;
            }
            if(x < x_y.x){
                dir = 3;
            }
        }
        else if(x == x_y.x){
            if(y > x_y.y){
                dir = 0;
            }
            if(y > x_y.y){
                dir = 1;
            }
        }
        std::cout << dir << ":DIR";
        attack(damage, x, y, dir);       
    }
    
};
