#include "textures/textures.h"
class hats{   
    
public:
    void attack(int damage){
        std::cout << "Size for attack your HAT is: " << damage << std::endl;
    }

    void break_hat(int* hp, int damage){
        *hp -= damage;
        std::cout << "Your HAT start broke, HP your HAT:" << *hp << std::endl;
    }  

    void info(int hp, int damage){
        std::cout << "\nYour HAT HP:" << hp << std::endl;
        std::cout << "Your HAT damage:" << damage << std::endl;
    }
};

class farmer_hat: public hats{
    private:   
        int damage = 10;
    public:
        int hp = 20;

        const int damage_pub = damage;

        std::string texture = farm_hat;
        std::string texture_cp = farm_hat_copy;

        farmer_hat(){
            std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
            info(hp, damage);
        }
        int safe(int hp){
            return hp;
        }
};
class santa_hat: public hats{
    private:   
        int damage = 10;

    public:
        int hp = 20;

        const int damage_pub = damage;

        std::string texture = santas_hat;
        std::string texture_cp = santas_hat_copy;

        santa_hat(){
            std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
            info(hp, damage);
        }
        int safe(int hp){
            return hp;
        }
};
class joker_hat: public hats{ 
    private:    
        int damage = 10; 

    public:
        int hp = 20;
        std::string texture = joke_hat;
        std::string texture_cp = joke_hat_copy;
        const int damage_pub = damage;

        joker_hat(){                        
            std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
            info(hp, damage);
        }
        int safe(int hp){
            return hp;
        }
};