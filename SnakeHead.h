#ifndef SNAKE_SNAKEHEAD_H
#define SNAKE_SNAKEHEAD_H


#include <vector>
#include <string>
#include "Board.h"
#include <SFML/Graphics.hpp>

enum HeadRotate : short {LEFT = 90, RIGHT = 270 , UP = 180, DOWN = 0};

class SnakeHead : public Board {
protected:
    int speed;
    int key_pressed;
    int snake_position_x_y[2];
    int length;
    int score;
    HeadRotate head_rotate;
    HeadRotate past_head_rotate;
    std::vector<short> position_x;
    std::vector<short> position_y;
    sf::Texture head_texture;
    sf::RectangleShape middle;
    sf::CircleShape tail;

public:
    SnakeHead();
    void set_pressed_button(short &key);
    void head_rotate_func(short &key);
    void check_edges();
    void check_collisions_food();
    void draw_snake(sf::RenderWindow &win);
    void update();
};



#endif
