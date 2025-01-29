#include "textures/textures.h"
class hats{   
private:
    std::string upgrades;
    std::string _texture;
public:
    void set_texture(std::string texture){
        _texture = texture;
        std::cout << "\n\n\n\n\n";        
        std::cout << _texture;
    }
};