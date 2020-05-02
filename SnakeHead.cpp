#include "SnakeHead.h"
#include "Board.h"
#include "Menu.h"
#include <iostream>

SnakeHead::SnakeHead() : tail(sf::CircleShape(20, 3))
{
    if (!head_texture.loadFromFile("../IMG/viper_head.png"))
    {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }

    score = 0;
    key_pressed = 72;
    past_head_rotate = head_rotate = RIGHT;
    length = 10;

    snake_position_x_y[0] = 300;
    snake_position_x_y[1] = 300;

    middle = sf::RectangleShape(sf::Vector2f(20, 20));
    middle.setPosition(280, 300);
    middle.setFillColor(sf::Color::Green);

    speed = 4;
}

void SnakeHead::set_pressed_button(short &key)
{
    //std::cout << key;

    head_rotate_func(key);
}

void SnakeHead::head_rotate_func(short &key)
{

    past_head_rotate = head_rotate;
    if (key_pressed != key)
    {
        if(key == 71 && past_head_rotate != RIGHT)
        {
            head_rotate = LEFT;
        }
        if(key == 72 && past_head_rotate != LEFT)
        {
            head_rotate = RIGHT;
        }
        if(key == 73 && past_head_rotate != DOWN)
        {
            head_rotate = UP;
        }
        if(key == 74 && past_head_rotate != UP)
        {
            head_rotate = DOWN;
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
    }
    if (head_rotate == LEFT)
    {
        position_x.push_back(snake_position_x_y[0]);
        position_y.push_back(snake_position_x_y[1]);
    }
    if (head_rotate == RIGHT)
    {
        position_x.push_back(snake_position_x_y[0]);
        position_y.push_back(snake_position_x_y[1]);
    }
    if (head_rotate == UP)
    {
        position_x.push_back(snake_position_x_y[0]);
        position_y.push_back(snake_position_x_y[1]);
    }
    if (head_rotate == DOWN)
    {
        position_x.push_back(snake_position_x_y[0]);
        position_y.push_back(snake_position_x_y[1]);
    }

    check_edges();

    if (head_rotate == LEFT)
        snake_position_x_y[0] -= speed;

    if (head_rotate == RIGHT)
        snake_position_x_y[0] += speed;

    if (head_rotate == UP)
        snake_position_x_y[1] -= speed;

    if (head_rotate == DOWN)
        snake_position_x_y[1] += speed;

}

void SnakeHead::check_edges()
{
    if (snake_position_x_y[1] > 600)
    {
        if (Mode != GOD)
            snake_position_x_y[1] = 0;
        else
            current_state = FINISHED;
    }

    if (snake_position_x_y[0] > 800)
    {
        if (Mode != GOD)
            snake_position_x_y[0] = 0;
        else
            current_state = FINISHED;
    }
    if (snake_position_x_y[1] < 0)
    {
        if(Mode != GOD)
            snake_position_x_y[1] = 600;
        else
            current_state = FINISHED;
    }

    if (snake_position_x_y[0] < 0)
    {
        if(Mode != GOD)
            snake_position_x_y[0] = 800;
        else
            current_state = FINISHED;
    }
}

void SnakeHead::draw_snake(sf::RenderWindow &win)
{
    for (int i = 0; i < length; ++i)
    {
        check_collisions_food();

        if(position_x[i] == position_x[length] && position_y[i] == position_y[length] && length > 20)
        {
            set_state(FINISHED);
        }
        else{
            middle.setPosition(position_x[i], position_y[i]);
            win.draw(middle);
        }
    }
}

void SnakeHead::check_collisions_food()
{
    int vec_size = Board::food.size();
    int max_position_x, min_position_x;
    int max_position_y, min_position_y;

    for (int i = 0; i < vec_size; ++i)
    {
        if(position_x[length] > food[i].food_position_x)
        {
            max_position_x = position_x[length];
            min_position_x = food[i].food_position_x;
        }
        else
        {
            min_position_x = position_x[length];
            max_position_x = food[i].food_position_x;
        }
        if(position_y[length] > food[i].food_position_y)
        {
            max_position_y = position_y[length];
            min_position_y = food[i].food_position_y;
        }
        else
        {
            min_position_y = position_y[length];
            max_position_y = food[i].food_position_y;
        }

        if (max_position_x - min_position_x < 20 && max_position_y - min_position_y < 20)
        {
            if (food[i].type == APPLE)
            {
                length += 1;
                ++score;
            }
            if(food[i].type == MUSHROOM)
            {
                score -=3;
                length -= 1;
            }
            if(food[i].type == TNT)
            {
                set_state(FINISHED);
            }

            add_food();
            remove_food(i);
        }
    }
}












