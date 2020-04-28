#ifndef SNAKE_SNAKEHEAD_H
#define SNAKE_SNAKEHEAD_H


#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class SnakeHead {

    int speed_low, speed_medium, speed_max;
    std::vector<short> length;
    std::string name;
    sf::Texture head_texure;

public:
    SnakeHead();
};



#endif
