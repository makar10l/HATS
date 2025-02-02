class AI : public hats{
    AIx_y.x = 11;
    AIx_y.y = 5;
    x = AIx_y.x;
    y = AIx_y.y;
    char search(){
        if(x == x_y.x){
            if(y > x_y.y){
                attack(damage, AIx_y, 2);
            }
            else{
                attack(damage, AIx_y, 3);
            }
        }
    }    
};