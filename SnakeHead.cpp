#include "SnakeHead.h"
#include <iostream>

SnakeHead::SnakeHead() : tail(sf::CircleShape(20, 3))
{
    key_pressed = 72;
    head_rotate = RIGHT;
    length = 3;

    snake_position_x = 300;
    snake_position_y = 300;
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
    middle = sf::RectangleShape(sf::Vector2f(20, 20));
    middle.setPosition(380, 300);
    middle.setFillColor(sf::Color::Red);

    tail.setPosition(360,snake_position_y);
    tail.setFillColor(sf::Color::Green);

    if (!head_texture.loadFromFile("../IMG/viper_head.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }
    angry_snake.setTexture(head_texture);
    angry_snake.setScale(0.2,0.2);
    angry_snake.setRotation(head_rotate);
    angry_snake.setPosition(snake_position_x,snake_position_y);

    speed = 4;
}

void SnakeHead::set_pressed_button(short &key)
{
    std::cout << key;

    head_rotate_func(key);
}

void SnakeHead::head_rotate_func(short &key)
{

    if (key_pressed != key)
    {
        if(key == 71)
        {
            head_rotate = LEFT;
            snake_position_y -= 45;
        }
        if(key == 72)
        {
            head_rotate = RIGHT;
            snake_position_y += 45;
        }
        if(key == 73)
        {
            head_rotate = UP;
            snake_position_x += 45;
        }
        if(key == 74)
        {
            head_rotate = DOWN;
            snake_position_x -= 45;
        }
    }
    key_pressed = key;
}

void SnakeHead::update()
{
    if (position_x.size() > length)
    {
        position_x.erase(position_x.begin());
        position_y.erase(position_y.begin());
    } else {
        position_x.push_back(snake_position_x);
        position_y.push_back(snake_position_y);
    }
    if (snake_position_y > 600)
        snake_position_y = 0;

    if (snake_position_x > 800)
        snake_position_x = 0;

    if (snake_position_y < 0)
    {
        snake_position_y = 600;
    }

    if (snake_position_x < 0)
    {
        snake_position_x = 800;
    }

    if (head_rotate == LEFT)
        snake_position_x -= speed;

    if (head_rotate == RIGHT)
        snake_position_x += speed;

    if (head_rotate == UP)
        snake_position_y -= speed;

    if (head_rotate == DOWN)
        snake_position_y += speed;


    std::cout <<snake_position_y << std::endl;

    middle.setPosition(position_x[0], position_y[0]);
    angry_snake.setRotation(head_rotate);
    angry_snake.setPosition(snake_position_x, snake_position_y);
}

void SnakeHead::tail_position()
{

}

