#ifndef SNAKE_SNAKEHEAD_H
#define SNAKE_SNAKEHEAD_H


#include <vector>
#include <string>
#include "Board.h"
#include <SFML/Graphics.hpp>

enum HeadRotate : short {LEFT = 90, RIGHT = 270 , UP = 180, DOWN = 0};

class SnakeHead : public Board {
protected:
    int speed, speed_max;
    int key_pressed;
    int snake_position_x;
    int snake_position_y;
    int length;
    HeadRotate head_rotate;

    std::vector<short> position_x;
    std::vector<short> position_y;

    sf::Texture head_texture;
    sf::Sprite angry_snake;
    sf::RectangleShape middle;
    sf::CircleShape tail;
public:
    SnakeHead();
    void set_pressed_button(short &key);
    void head_rotate_func(short &key);
    void tail_position();
    void update();
};



#endif
