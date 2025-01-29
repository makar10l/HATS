#include "textures/textures.h"
class hats{   
public:
    float hp = 0;
    float damage = 0;
    
    void info(){
        std::cout << "\nYour HAT HP:" << hp << std::endl;
        std::cout << "Your HAT damage:" << damage << std::endl;
    }
};

class farmer_hat: public hats{
    public:
    std::string texture = farm_hat;
    std::string texture_cp = farmer_hat_copy;
    farmer_hat(){
        std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
        info();
    }
};
class santa_hat: public hats{
    public:
    std::string texture = santas_hat;
    std::string texture_cp = santas_hat_copy;
    santa_hat(){
        std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
        info();
    }
};
class joker_hat: public hats{
    public:
    std::string texture = joke_hat;
    std::string texture_cp = joke_hat_copy;
    joker_hat(){
        std::cout << "\t\tITS YOUR HAT" << std::endl  << texture_cp;
        info();
    }
};