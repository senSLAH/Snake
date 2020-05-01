#ifndef SNAKE_BOARD_H
#define SNAKE_BOARD_H

#include <vector>
#include <SFML/Graphics.hpp>

enum FoodType : short { APPLE, MUSHROOM, BOMB };

struct Food
{
    short food_position_x;
    short food_position_y;
    FoodType type;
};

class Board{
    int current_time;
    int past_time;
    int time;
    short food_count;
    Food f;
    sf::Texture apple_texture;
    sf::Sprite appple;
    std::vector<Food> food;

public:
    Board();
    void add_food();
    void remove_food();
    void timer(int ms);
    void draw_food(sf::RenderWindow &win);

};



#endif
